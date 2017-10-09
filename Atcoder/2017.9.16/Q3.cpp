#include <cstdio>
#include <algorithm>



int main(){
    float a, b, c, d, e, f;

    scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);

    float water[] = {a * 100, b * 100, (a + b) * 100}, sugar[] = {c, d, c + d};

    float ratio = 0.0f;

    float ans_water, ans_sugar;

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(water[i] * e / 100 < sugar[j] || water[i] + sugar[j] > f){
                continue;
            }
            if(ratio < sugar[j] / (water[i] + sugar[j])){
                ratio = sugar[j] / (water[i] + sugar[j]);
                ans_water = water[i];
                ans_sugar = sugar[j];
            }
        }
    }

    printf("%d %d\n", int(ans_water + ans_sugar), int(ans_sugar));

    return 0;
}
