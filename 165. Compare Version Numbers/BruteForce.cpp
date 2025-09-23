class Solution {
public:
    int compareVersion(string a, string b) {
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i < a.size(); i++){
            int num = 0;
            while(a[i] != '.' && i < a.size()){
                    // build the string
                    num *= 10;
                    num += (a[i] - '0');
                    i++;
            }
            v1.push_back(num); 
            num = 0;
            // reset
        }


        for(int i = 0; i < b.size(); i++){
            int num = 0;
            while(b[i] != '.' && i < b.size()){
                    // build the string
                    num *= 10;
                    num += (b[i] - '0');
                    i++;
            }
            v2.push_back(num); 
            num = 0;
            // reset
        }

        // 1st step done

        // creation of vectors

        // we wil compare the size of vectros
        while(v1.size() < v2.size()){
            v1.push_back(0);
        }
        while(v1.size() > v2.size()){
            v2.push_back(0);
        }
        for(auto i : v1){
            cout<<i<<", ";
        }
        cout<<endl;

        for(auto i : v2){
            cout<<i<<", ";
        }
        cout<<endl;
        // 3. compare the created vectors
        for(int i = 0 ; i < v1.size(); i++){
            if(v1[i] > v2[i]){
                return 1;
            }
            else if(v1[i] < v2[i]){
                return -1;
            }
        }
        return 0;
    }
};
