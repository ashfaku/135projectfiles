#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "dsexceptions.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include "sequence_map.h"
using namespace std;

// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class AvlTree
{
public:
	/*
		Skips first 10 lines, then parses input file for recognition sequence and enzyme acronym pairings
	*/
	void parse(const string &db_filename)
	{
		ifstream read(db_filename);
		string holder;
		int i = 0;
		while (i < 10)
		{
			getline(read, holder);
			i++;
		}
		while (getline(read, holder))
		{
			size_t slash = holder.find('/');
			string acr = holder.substr(0, slash);
			holder = holder.substr(slash + 1);
			slash = holder.find('/');
			while (slash != string::npos)
			{
				string recog = holder.substr(0, slash);
				holder = holder.substr(slash + 1);
				slash = holder.find('/');
				if (recog.size() != 0)
				{
					SequenceMap new_map_(recog, acr);
					insert(new_map_);
				}
			
			}
		}
	}
/*
		returns internal path length of tree
	*/
	int getPathLength()
	{
		return getPathLength(root, 0);
	}
	/*
		returns how many nodes are in the tree
	*/
	int getNodeCount()
	{
		return nodeCount;
	}
	/*
		Returns whether a node exists in the tree, prints its acronyms if it does and returns true, false otherwise
	*/
	bool printNode(const Comparable & x)
	{
		return printNode(x, root);
	}
	/*
		find() function akin to contains, except it counts recursive calls
	*/
	int find(const Comparable & x)
	{
		if (!contains(x, root))
			return 0;
		return find(x, root);
	}
	AvlTree( ) : root{ nullptr } , nodeCount{ 0 } , minCount { 0 }
	{ }

	AvlTree( const AvlTree & rhs ) : root{ nullptr }
	{
		root = clone( rhs.root );
		nodeCount = rhs.nodeCount;
		minCount = rhs.minCount;
	}

	AvlTree( AvlTree && rhs ) : root{ rhs.root }
	{
		rhs.root = nullptr;
	}

	~AvlTree( )
	{
		makeEmpty( );
	}

	/**
	 * Deep copy.
	 */
	AvlTree & operator=( const AvlTree & rhs )
	{
		AvlTree copy = rhs;
		std::swap( *this, copy );
		return *this;
	}

	/**
	 * Move.
	 */
	AvlTree & operator=( AvlTree && rhs )
	{
		std::swap( root, rhs.root );

		return *this;
	}

	/**
	 * Find the smallest item in the tree.
	 * Throw UnderflowException if empty.
	 */
	const Comparable & findMin( ) const
	{
		if( isEmpty( ) )
			throw UnderflowException{ };
		return findMin( root )->element;
	}

	/**
	 * Find the largest item in the tree.
	 * Throw UnderflowException if empty.
	 */
	const Comparable & findMax( ) const
	{
		if( isEmpty( ) )
			throw UnderflowException{ };
		return findMax( root )->element;
	}

	/**
	 * Returns true if x is found in the tree.
	 */
	bool contains( const Comparable & x ) const
	{
		return contains( x, root );
	}

	/**
	 * Test if the tree is logically empty.
	 * Return true if empty, false otherwise.
	 */
	bool isEmpty( ) const
	{
		return root == nullptr;
	}

	/**
	 * Print the tree contents in sorted order.
	 */
	void printTree( ) const
	{
		if( isEmpty( ) )
			cout << "Empty tree" << endl;
		else
			printTree( root );
	}

	/**
	 * Make the tree logically empty.
	 */
	void makeEmpty( )
	{
		makeEmpty( root );
	}

	/**
	 * Insert x into the tree; duplicates are ignored.
	 */
	void insert( const Comparable & x )
	{
		insert( x, root );
	}

	/**
	 * Insert x into the tree; duplicates are ignored.
	 */
	void insert( Comparable && x )
	{
		insert( std::move( x ), root );
	}

	/**
		 Remove x from the tree. Nothing is done if x is not found.
	*/
	void remove( const Comparable & x )
	{
		remove( x, root , minCount);
	}
	/*
		Public function to count recursive calls of removal, and removing the element still
	*/
	int checkRemovable(const Comparable & x)
	{
		int count = 0;
		if (!contains(x))
			return 0;
		checkRemovable(x, root, count);
		return count;
	}
	/*
		Accessor function to return total calls of minCount
	*/
	int getMinCount()
	{
		return minCount;
	}

private:
	struct AvlNode
	{
		Comparable element;
		AvlNode   *left;
		AvlNode   *right;
		int       height;

		AvlNode( const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
			: element{ ele }, left{ lt }, right{ rt }, height{ h } { }

		AvlNode( Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
			: element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
	};
	AvlNode *root;
	int nodeCount;
	int minCount;
	/*
		Private helper function to count recursive calls
	*/
	int find(const Comparable & x, AvlNode * & t)
	{
		if (t == nullptr)
			return 0;
		else if( x < t->element )
			return 1 + find( x, t->left );
		else if( t->element < x )
			return 1 + find( x, t->right );
		else	
			return 1;

	}
	/*
		Private helper function to get the internal path length
	*/
	double getPathLength(AvlNode * x, int depth)
	{
		if (x == nullptr)
			return 0;
		return getPathLength(x->left, depth+1) + getPathLength(x->right, depth+1) + depth;
	}

	/**
	 * Internal method to insert into a subtree.
	 * x is the item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void insert( const Comparable & x, AvlNode * & t )
	{
		if( t == nullptr )
		{
			t = new AvlNode{ x, nullptr, nullptr };
			nodeCount++;
		}
		else if( x < t->element )
			insert( x, t->left );
		else if( t->element < x )
			insert( x, t->right );
		else	
			t->element.Merge(x);
		balance( t );
	}

	/**
	 * Internal method to insert into a subtree.
	 * x is the item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void insert( Comparable && x, AvlNode * & t )
	{
		if( t == nullptr )
			t = new AvlNode{ std::move( x ), nullptr, nullptr };
		else if( x < t->element )
			insert( std::move( x ), t->left );
		else if( t->element < x )
			insert( std::move( x ), t->right );
		else
			t->element->Merge(x);
		balance( t );
	}

	/**
	 * Internal methods to remove from a subtree.
	 * x is the item to remove.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.

	 Counts recursive calls
	 */
	void checkRemovable( const Comparable & x, AvlNode * & t, int& count )
	{
		if( t == nullptr )
		{
			return;
		}   // Item not found; do nothing
		else if( x < t->element )
		{
			count++;
			checkRemovable( x, t->left, count );
		}
		else if( t->element < x )
		{
			count++;
			checkRemovable( x, t->right, count);
		}
		else if( t->left != nullptr && t->right != nullptr ) // Two children
		{
			minCount++;
			t->element = findMin( t->right , count)->element;
			count++;
			checkRemovable( t->element, t->right, count );

		}
		else
		{
			AvlNode *oldNode = t;
			t = ( t->left != nullptr ) ? t->left : t->right;
			nodeCount--;
			//idk
			delete oldNode;
		}
		balance( t );
	}
	void remove( const Comparable & x, AvlNode * & t)
	{
		if( t == nullptr )
			return;   // Item not found; do nothing

		if( x < t->element )
			remove( x, t->left );
		else if( t->element < x )
			remove( x, t->right );
		else if( t->left != nullptr && t->right != nullptr ) // Two children
		{
			t->element = findMin( t->right )->element;
			remove( t->element, t->right );
		}
		else
		{
			AvlNode *oldNode = t;
			t = ( t->left != nullptr ) ? t->left : t->right;
			nodeCount--;
			delete oldNode;
		}

		balance( t );



	}

	static const int ALLOWED_IMBALANCE = 1;

	// Assume t is balanced or within one of being balanced
	void balance( AvlNode * & t )
	{
		if( t == nullptr )
			return;

		if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE ) {
			if( height( t->left->left ) >= height( t->left->right ) )
				rotateWithLeftChild( t );
			else
				doubleWithLeftChild( t );
		} else if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE ) {
			if( height( t->right->right ) >= height( t->right->left ) )
				rotateWithRightChild( t );
			else
				doubleWithRightChild( t );
		}
		t->height = max( height( t->left ), height( t->right ) ) + 1;
	}

	/**
	 * Internal method to find the smallest item in a subtree t.
	 * Return node containing the smallest item.
	 */
	AvlNode * findMin( AvlNode *t , int& count)
	{
		if( t == nullptr )
			return nullptr;
		if( t->left == nullptr )
			return t;
	
		minCount++;		
		return findMin( t->left , count);
	}

	/**
	 * Internal method to find the largest item in a subtree t.
	 * Return node containing the largest item.
	 */
	AvlNode * findMax( AvlNode *t ) const
	{
		if( t != nullptr )
			while( t->right != nullptr )
				t = t->right;
		return t;
	}
	/*
		Private helper function to print node->element->acronyms if it exists
	*/
	bool printNode( const Comparable & x, AvlNode *t ) const
	{
		if( t == nullptr )
			return false;
		else if( x < t->element )
			return printNode( x, t->left );
		else if( t->element < x )
			return printNode( x, t->right );
		else
		{
			vector<string> acronyms = t->element.getAcronyms();
			for (string s: acronyms)
			{
				cout << s << " ";
			}
			cout << endl;
			return true;    // Match
		}
	}
	/**
	 * Internal method to test if an item is in a subtree.
	 * x is item to search for.
	 * t is the node that roots the tree.
	 */
	bool contains( const Comparable & x, AvlNode *t ) const
	{
		if( t == nullptr )
			return false;
		else if( x < t->element )
			return contains( x, t->left );
		else if( t->element < x )
			return contains( x, t->right );
		else
		{
			return true;    // Match
		}
	}
	/****** NONRECURSIVE VERSION*************************
	    bool contains( const Comparable & x, AvlNode *t ) const
	    {
	        while( t != nullptr )
	            if( x < t->element )
	                t = t->left;
	            else if( t->element < x )
	                t = t->right;
	            else
	                return true;    // Match

	        return false;   // No match
	    }
	*****************************************************/

	/**
	 * Internal method to make subtree empty.
	 */
	void makeEmpty( AvlNode * & t )
	{
		if( t != nullptr )
		{
			makeEmpty( t->left );
			makeEmpty( t->right );
			delete t;
		}
		t = nullptr;
	}

	/**
	 * Internal method to print a subtree rooted at t in sorted order.
	 */
	void printTree( AvlNode *t ) const
	{
		if( t != nullptr )
		{
			printTree( t->left );
			cout << t->element << endl;
			printTree( t->right );
		}
	}

	/**
	 * Internal method to clone subtree.
	 */
	AvlNode * clone( AvlNode *t ) const
	{
		if( t == nullptr )
			return nullptr;
		else
			return new AvlNode{ t->element, clone( t->left ), clone( t->right ), t->height };
	}
	// Avl manipulations
	/**
	 * Return the height of node t or -1 if nullptr.
	 */
	int height( AvlNode *t ) const
	{
		return t == nullptr ? -1 : t->height;
	}

	int max( int lhs, int rhs ) const
	{
		return lhs > rhs ? lhs : rhs;
	}

	/**
	 * Rotate binary tree node with left child.
	 * For AVL trees, this is a single rotation for case 1.
	 * Update heights, then set new root.
	 */
	void rotateWithLeftChild( AvlNode * & k2 )
	{
		AvlNode *k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
		k1->height = max( height( k1->left ), k2->height ) + 1;
		k2 = k1;
	}

	/**
	 * Rotate binary tree node with right child.
	 * For AVL trees, this is a single rotation for case 4.
	 * Update heights, then set new root.
	 */
	void rotateWithRightChild( AvlNode * & k1 )
	{
		AvlNode *k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
		k2->height = max( height( k2->right ), k1->height ) + 1;
		k1 = k2;
	}

	/**
	 * Double rotate binary tree node: first left child.
	 * with its right child; then node k3 with new left child.
	 * For AVL trees, this is a double rotation for case 2.
	 * Update heights, then set new root.
	 */
	void doubleWithLeftChild( AvlNode * & k3 )
	{
	//	rotateWithRightChild( k3->left );
	//	rotateWithLeftChild( k3 );
		AvlNode *left = k3->left;     
		AvlNode *left_right = left->right;    
		k3->left = left_right->right;     
		left->right = left_right->left;     
		left_right->left = left;
		left_right->right=k3;     
		k3->height = max(height(k3->left) , height(k3->right))+1;    
		left->height =  max(height(left->left) , height(left->right))+1;   
		left_right->height = max(left->height , k3->height)+1;   
		k3 = left_right;
	}

	/**
	 * Double rotate binary tree node: first right child.
	 * with its left child; then node k1 with new right child.
	 * For AVL trees, this is a double rotation for case 3.
	 * Update heights, then set new root.
	 */
	void doubleWithRightChild( AvlNode * & k3 )
	{
		//rotateWithLeftChild( node->right );
		//rotateWithRightChild( node );

		AvlNode *right = k3->right;      
		AvlNode *right_left = k3->right->left;      
		k3->right = right_left->left;      
		right->left = right_left->right;      
		right_left->left = k3;      
		right_left->right = right;   
		k3->height = max(height(k3->left) , height(k3->right))+1;     
		right->height =  max(height(right->left) , height(right->right))+1;     
		right_left->height = max(right->height , k3->height)+1;     
		k3 = right_left;
	
	}

};

#endif
