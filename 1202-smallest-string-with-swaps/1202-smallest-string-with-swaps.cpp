class DSU{
    public:
      vector<int>parent,rank;
      void init(int n){
          for(int i = 0; i < n; i++){
              parent[i] = i;
              rank[i] = 0;
          }
      }
      DSU(int n){
          parent.resize(n);
          rank.resize(n);
          init(n);
      }
      
      void Union(int u,int v){
          int pu = FindParent(u);
          int pv = FindParent(v);
          if(pu == pv){
              return;
          }
          else if(rank[pu] >= rank[pv]){
              parent[pv] = u;
              rank[pu]++;
          }else{
              parent[pu] = v;
              rank[pv]++;
          }
      }
      
      int FindParent(int node){
          if(parent[node] == node){
              return node;
          }
          return parent[node] = FindParent(parent[node]);
      }   
  };

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int> >& pairs) {
        int n = pairs.size();
        int m = s.size();
        DSU obj(m);
        // for(auto it : obj.parent){
        //     cout << it << " ";
        // }
        
        for(int i = 0; i < n; i++){
            int u = pairs[i][0];
            int v = pairs[i][1];
            // cout << u  << " "<< v << endl;
            obj.Union(u,v);
        }
        
        unordered_map<int,vector<int> > mpp;
        for(int i = 0; i < m; i++){
            int ultimateParent = obj.FindParent(i);
            // cout << ultimateParent << " " << i << endl;
            mpp[ultimateParent].push_back(i);
        }
        
        for(auto it : mpp){
            string temp = "";
            for(auto str : it.second){
                temp += s[str];
            }
            // cout << temp << " ";
            sort(temp.begin(),temp.end());
            int j = 0;
            for(auto i : it.second){
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};