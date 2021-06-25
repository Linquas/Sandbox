class Solution { // Exceed Time limit
private:
    int minJump = 10000;
    void traverse(vector<int>& obstacles, int currentLane, int jump, int count) {
        if (count == obstacles.size()-1) {
            if (jump < minJump) {
                minJump = jump;
            }
            return;
        } else {
            if (obstacles[count] != currentLane) { // no obstacle
                traverse(obstacles, currentLane, jump, count+1);
            } else {
                for (int i = 1; i <= 3; ++i) {
                    if (i != currentLane) {
                        if (i != obstacles[count-1]) {
                            traverse(obstacles, i, jump + 1, count+1);   
                        }
                    }
                }
            }
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        traverse(obstacles, 2, 0, 1);
        return minJump;
    }
};