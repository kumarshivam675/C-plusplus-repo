#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int input,ans;
	int n,sx,sy,ex,ey,bx,by;
	cin >> input;
	for(int i = 0; i < input; i++){
		ans = 0;
		cin >> n >> sx >> sy >> ex >> ey;
		cin >> bx >> by;
		if(sx == ex && sy != ey){
			if(bx == sx){
				if(sy < ey){
				    if(by > sy && by < ey)
				        ans += 2;
				}
				else if(sy > ey){
				    if(by < sy && by > ey)
				        ans += 2;
				}
			}
			ans += abs(sy - ey);
		}
		else if(sy == ey && sx != ex){
			if(by == sy){
			   if(sx < ex){
				    if(bx > sx && bx < ex)
				        ans += 2;
				}
				else if(sx > ex){
				    if(bx < sx && bx > ex)
				        ans += 2;
				}
			}
			ans += abs(sx - ex);
		}
		else{
			ans += (abs(sx - ex) + abs(sy - ey));
		}
		cout << ans << endl;
	}
	return 0;
}
