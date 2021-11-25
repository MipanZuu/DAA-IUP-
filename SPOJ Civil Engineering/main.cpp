//
//  main.cpp
//  SPOJ Civil Engineering
//
//  Created by Denta Bramasta Hidayat on 22/09/21.
//

#include <bits/stdc++.h>
int main() {
    double h,w,f;
    while(scanf("%lf %lf %lf", &h, &w, &f) && (h!=0 && w!=0 && f!=0)) {
        double a = (4.0 * h) / (w * w);
        double func = ((f * f) - 1.0) / (4.0 * a);
        printf("%.3lf\n", func);
    }
    
}
