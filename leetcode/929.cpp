class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        vector<string> sends;
        string temp;
        for(auto it = emails.begin(); it != emails.end(); it++)
        {
            temp.clear();
            for(auto it1 = (*it).begin(); it1 != (*it).end(); it1++)
            {
                if((*it1)=='@'||(*it1)=='+')
                {
                    break;
                }else if((*it1)=='.'){
                    continue;
                }else{
                    temp.push_back(*it1);
                }
            }
            auto it1 = (*it).begin();
            for(it1 = (*it).begin(); it1!=(*it).end(); it1++) if((*it1)=='@') break;
            for(;it1!=(*it).end(); it1++) temp.push_back(*it1);
            if(find(sends.begin(),sends.end(),temp)==sends.end()) sends.push_back(temp);
        }
        return sends.size();
    }
};