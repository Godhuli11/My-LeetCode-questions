class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        
        int lftptr=0,rghtptr=s.size()-1;

        while(s[lftptr]==s[rghtptr]&&rghtptr>lftptr)
        {
            char temp=s[lftptr];
            while(s[lftptr]==temp&&lftptr<n)
            {
                lftptr++;
            }
            while(s[rghtptr]==temp&&rghtptr>0)
            {
                rghtptr--;
            }
            if(rghtptr<lftptr)
            {
                return 0;
            }
        }
        return rghtptr-lftptr+1;
    }
};