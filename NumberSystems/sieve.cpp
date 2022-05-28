class Solution
{
public:
    bool primes[10005];
    void sieve(){
        primes[0]=primes[1]=false;
        for(int i=2;i*i<=10004;i++){
            if(primes[i]){
                for(int j=i*i;j<=10004;j+=i){
                    primes[j]=false;
                }
            }
        }
    }
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> ans;
        memset(primes,true, sizeof(primes));
        sieve();
        for(int i=2;i<=N;i++){
            if(primes[i]) ans.push_back(i);
        } 
        return ans;
    }
};
