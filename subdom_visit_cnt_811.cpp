//https://leetcode.com/problems/subdomain-visit-count/description/
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> vals;
        vector<string> out;
        for(auto str:cpdomains){
            size_t fndVal=str.find(" ");
            string num=str.substr(0,fndVal);
            str=str.substr(fndVal+1);
            fndVal=str.find(".");
           // cout<<fndVal<<" "<<str<<endl;
            int numVal=stoi(num);
            while(fndVal != std::string::npos){
                vals[str] += numVal;
                str=str.substr(fndVal+1);
                fndVal=str.find(".");
                //cout<<fndVal<<" "<<str<<endl;
                if(fndVal == std::string::npos){
                    vals[str] += numVal;
                    break;
                }
            }
        }
        for(auto obj:vals){
            string val=to_string(obj.second);
            string name=obj.first;
            string outStr=val+" "+name;
            out.push_back(outStr);
        }
        return out;
    }
};
