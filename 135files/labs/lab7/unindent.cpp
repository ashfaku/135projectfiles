int countChar(string l, char s)
{
        int c = 0, index = -1;
        while (l[++index])
                c += (l[index] == s ? 1 : 0);
        return c;
}
string removeLeadingSpaces(string s)
{
        string r = "";
        int i = -1;
        while (isspace(s[++i]));
        for (; i < s.length(); i++)
                r += s[i];
        return r;
}
