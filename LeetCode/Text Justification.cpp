class Solution
{
public:
    vector<string> fullJustify(vector<string> &w, int check)
    {
        vector<string> ans;
        int i = 0;
        while (i < w.size())
        {
            int end = i;
            int space = 0;
            int word = 0;
            string s = "";
            int word_length = 0;
            for (int j = i; j < w.size(); j++)
            {
                if (j == i)
                {
                    word++;
                    word_length += w[j].size();
                }
                else
                {
                    if (word_length + space + 1 + w[j].size() > check)
                        break;
                    else
                    {
                        space++;
                        word++;
                        word_length += w[j].size();
                        end = j;
                    }
                }
            }
            if (end != w.size() - 1)
            {
                int extra = 0;
                int spc = 0;
                if (space)
                {
                    spc = (check - word_length) / space;
                    extra = (check - word_length) % space;
                }
                for (int j = i; j <= end; j++)
                {
                    s += w[j];
                    for (int k = 0; k < spc && j != end; k++)
                    {
                        s += " ";
                    }
                    if (extra)
                    {
                        extra--;
                        s += " ";
                    }
                }
                if (space == 0)
                {
                    int k = s.size();
                    for (int j = 1; j <= (check - k); j++)
                    {
                        s += " ";
                    }
                }
            }
            else
            {
                for (int j = i; j <= end; j++)
                {
                    if (j == i)
                        s += w[j];
                    else
                    {
                        s += " ";
                        s += w[j];
                    }
                }
                int k = s.size();
                for (int j = 1; j <= (check - k); j++)
                {
                    s += " ";
                }
            }
            i = end + 1;
            ans.push_back(s);
        }
        return ans;
    }
};
