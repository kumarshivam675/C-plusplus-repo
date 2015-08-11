#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    long long int input,a,b,c,key,ans;
    long double temp,ans_temp,d;
    cin >> input;
    for(int i = 0; i < input; i++){
    	cin >> a >> b >> c >> key;
    	c = c - key;
    	//cout << a << " " << b << " " << c << endl;
     	/*if(a < 0){
    		a = -1*a;
    		b = -1*b;
    		c = -1*c;
    	}*/
    	if(a >= 0){
			temp = b*b - 4*a*c;
			//cout << temp << endl;
			if(temp >= 0){
				d = sqrt(temp);
				//cout << d << endl;	
				ans_temp = (-1*b + d)/(2*a);
				//cout << d << " " << ans_temp << endl;
				ans = ceil(ans_temp);
				cout << ans << endl;
			}
			else if(temp < 0){
				cout << "0" << endl;
			}
		}
		
		if(a < 0){
			if(a < 0){
				a = -1*a;
				b = -1*b;
				c = -1*c;
    		}
    		temp = b*b - 4*a*c;
    		//cout << temp << endl;
			if(temp >= 0){
				d = sqrt(temp);
				//cout << d << endl;	
				ans_temp = (-1*b - d)/(2*a);
				//cout << d << " " << ans_temp << endl;
				ans = ceil(ans_temp);
				if(ans < 0)
					ans = 0;
				cout << ans << endl;
			}
		
		}
    }
    return 0;
}

