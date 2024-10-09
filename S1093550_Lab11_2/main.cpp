#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <algorithm> // std::sort
#include <cmath>
using namespace std;


int main() {
	int a[500];
	a[0] = 0 ;
    int s[500];
	int c;


		int cnt = 0;
		while((c = getchar()) != EOF ){
			if( c == ' ') {

				cnt++;
				if(cnt%2 ==0) a[cnt/2] = 0;
				if(cnt%2 ==1 )s[cnt/2] = 0;
				continue;
			}

			if( c == '\n'){
				cnt++;
				cnt /= 2; // CNT = NUMBER OF PAIRS (AVENUES,STREETS)


				sort(a, a + cnt);
				sort(s, s + cnt);


				int beststreet = s[cnt/2];
				int bestavenue = a[cnt/2];

				int tmp = 0;

				for(int k = 0; k < cnt; ++k){
					tmp += abs(a[k]-bestavenue) + abs(s[k]-beststreet);

				}

				cout << tmp << endl;
				cnt = 0;
				a[0] = 0;

				continue;
			}


			if(cnt%2 ==0) { // IF CNT IS ODD, THEN WE ARE READING AN AVENUE
				a[cnt/2] = 10*a[cnt/2] + (c - '0');

			}
			if(cnt%2 == 1) { // IF CNT IS EVEN, THEN ITS A STREET
				s[cnt/2] = 10*s[cnt/2] + (c - '0');

			}

		}


	return 0;
}
