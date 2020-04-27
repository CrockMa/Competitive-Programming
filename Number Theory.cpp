/*
	Name: Prathamesh Shendarkar
	My Motto: IS TO NEVER GIVE UP
	My Belief: If you are not able to solve a particular question don't copy and paste a solution, 
			  no one is going to look into your account and tell you that, oh my look he has solved so many questions, 
			  remeber you are cheating on yourself, Just try to solve that question after some time or some days, 
			  or look upon a solution and check for the intiution or approach they have used, 
			  But never mug up there solution. 
			  Go for Learning don't copy plz.
*/

#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ins insert
#define mp make_pair
#define len(s) s.length()
#define loopa(i,a,b) for( i=a;i<=b;i++)
#define loop(i,n)    for( i=0;i<n;i++)
#define pool(i,n)    for( i=n-1;i>=0;i--)
#define poop(i,a,b) for( i=a;i>=b;i--)
#define on cout<<endl
#define o2(a,b) cout<<a<<" "<<b
#define debug(a) cout<<a<<"\n";
#define os cout<<" "
#define all(v) v.begin(),v.end()
#define mem(n,m) memset(n,m,sizeof(n))
#define pii pair<int,int>
#define pll pair<long long,long long>
#define sii set<int>
#define sll set<long long>
#define vii vector<int> 
#define vll vector<long long>
#define mll map<long long, long long>
#define lob lower_bound
#define upb upper_bound
#define ret return 0
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define ford(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define fors(container, it, a, b) for(__typeof(container.begin()) it = a; it != b; it++) 

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define inf 999999999999999999
#define siz 100001
#define SIZ 1000001
#define SIZE 200001

typedef long long  ll;
typedef long double  ldo;
typedef double  db ;
using namespace std;

ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}

ll exp(ll x,ll y){ 
	ll res=1;
	x=x%mod;
	while(y>0) 
	{ 
		if(y&1) 
			res=(res*x)%mod; 
		y = y>>1;
		x=(x*x)%mod; 
	} 
	return res; 
}

// This is fermat's little theorem
ll exp_mod(ll x,ll y, ll p){ 
	ll res=1;
	x=x%p;
	while(y>0) 
	{ 
		if(y&1) 
			res=(res*x)%p; 
		y = y>>1;
		x=(x*x)%p; 
	} 
	return res; 
} 

using namespace std;

// This is extended eucledian algorithm
ll d,x,y;
void extended_euclid(ll a, ll b){
	if(b == 0){
		d = a;
		x = 1;
		y = 0;
	}else{
		extended_euclid(b, a%b);
		int temp = x;
		x = y;
		y = temp - (a/b)*y;
	}
}

ll mod_inverse(ll a, ll p){
	extended_euclid(a,p);
	return (x%p + p)%p;
}

// To Check if any number is a multiple of any other number or how many numbers in a string are there which are multiple of k integer
// It is from ATcoder 164 contest D Task
ll multiplesofnumber(string s, ll m){
	vector<ll> v(2019);
	v[0] = 1;
	ll n = s.size();
	ll ans = 0,r = 0,x = 1;
	for(ll i = n - 1;i>=0;i--){
		r = (r + (s[i] - '0')*x)%m;
		r = r%m;
		x = (x*10)%m;
		ans += v[r];
//		cout << ans << " " << v[r] << "\n";
		v[r]++;
	}	
	return ans;
}

// It's all about prime numbers now and divisors and factors
// 1. To check if number is prime or not
bool check_prime(ll n){
	ll cnt = 0;
	for(ll i = 1;i<=sqrt(floor(n));i++){
		if(n%i == 0){
			if(i*i == n)
				cnt++;
			else
				cnt+= 2;
		}
	}
	return cnt > 2 ? false : true;
}

// 2. Now to generate all prime numbers
vector<ll> generate_primes(ll n){
	vector<ll> v;
	bool arr[n + 1];
	memset(arr, true, sizeof(arr));
	arr[0] = arr[1] = false;
	for(ll i = 2;i*i<=n;i++){
		if(arr[i]){
			for(ll j = i*i;j<=n;j+=i){
				arr[j] = false;
			}
		}
	}
	for(ll i = 1;i<=n;i++) {
		if(arr[i]) 
			v.push_back(i);	
	}
	return v;
}

// 3. To generate factors of a number
vector<ll> factors_of_a_number(ll n){
	vector<ll> v;
	for(ll i = 2;i*i<=n;i++){
		while(n%i == 0){
			v.push_back(i);
			n /= i;
		}
	}
	if(n != 1)
		v.push_back(n);
	return v;
}
int main(){
    fastio;
    
    // 1. To calculate Modular Multiplicative Inverse using fermat's little theorem
    // It is used in div of two numbers with mod, i.e (a/b)%mod => (a%mod * x%mod)%mod , where x 
    // Is nothing but multiplicative inverse of a
    // This was fermat little theorem
//	 ll a,p;
//	 cin >> a >> p;
//	 cout << exp_mod(a, p - 2, p) << "\n";
	
	// 2. TO calculate gcd, function is present above The time complexity is O(log(max(A, B))).
	// This is extended eucledian algo
//	cout << mod_inverse(a, p) << "\n";
//	string s;
//	cin >> s;
//	cout << multiplesofnumber(s,2019) << "\n";
	
	// For Prime numbers 
//	ll n;
//	cin >> n;
//	cout << check_prime(n) << "\n";

	// To generate all prime numbers in a given range in nloglogn time complexity (not great)
//	ll a,b;
//	cin >> a >> b;
//	vector<ll> v = generate_primes(b);
//	for(auto &x: v) cout << x << " " << "\n";

	// Now to generate all factors in o(n^1/2) time compo
	ll n;
	cin >> n;
	vector<ll> v = factors_of_a_number(n);
	for(auto &x:v) cout << x << " "; // You can't use debug macro everywhere, not a good sign.
}


/* <--SOME IMPORTANT CONCEPTS-->
  #1.
  ascii value for A-Z 065-096
  ascii value for a-z 097-122
  conversion:  lower=upper+32
  
  #2.
  converting a number to string:
  
  step:1 include the following class:
          #include<sstream>
  step:2  ostringstream st;
  
  step 3: st<<num
  
  step 4: string s=st.str();
  
  #3 
  converting a string to number
  
  step:1 include the following class:
          #include<sstream>
  
  step:2  stringstream val(s); //s is the string
  
  step:3  int y=0;
  
  step 4: val>>y;
  
  now y is the numeric form of the string

#4
  
  sorting in descending order
  
  sort(arr, arr+n, greater<int>());
 #5
  
  to convert a char to numeric
  (the character is c)
   c-'0'

 #6
  
  for(int &x:a)
  cin>>x;
  for(int &x:b)
  cout<<x<<" ";

#7    [bitwise left shift] 
       1<<n=pow(2,n)

#8
        [bitwise right shift]

         n>>k=n/pow(2,k)

#9
 clock_t start, end; 
  start = clock(); 
fun();
end = clock(); 

double time_taken 
        = double(end - start) 
          / double(CLOCKS_PER_SEC); 

cout << "Execution time: " << time_taken 
         << " secs";


*/



