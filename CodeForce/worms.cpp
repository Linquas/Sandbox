#include <bits/stdc++.h>
 
using namespace std;
 
void findJucyWorm(vector<int> &worms, int target)
{
    int start = 0;
    int end = (int)worms.size();
 
    while (end > start) {
        int mid = start + (end - start) / 2;
        if (worms[mid] >= target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
 
    printf("%d\n", start + 1);
}
 
int main()
{
    int piles = 0;
    scanf("%d", &piles);
 
    vector<int> pileOfWorms(piles, 0);
 
    for (int i = 0; i < piles; ++i) {
        int worm = 0;
        scanf("%d", &worm);
        if (i == 0) {
            pileOfWorms[i] = worm;
        } else {
            pileOfWorms[i] = pileOfWorms[i - 1] + worm;
        }
    }
 
    int numberOfJucyWorm = 0;
    scanf("%d", &numberOfJucyWorm);
 
    vector<int> targets(numberOfJucyWorm, 0);
    for (int i = 0; i < numberOfJucyWorm; ++i) {
        int target = 0;
        scanf("%d", &target);
        targets[i] = target;
    }
 
    for (const auto &target : targets) {
        findJucyWorm(pileOfWorms, target);
    }
 
    return 0;
}
