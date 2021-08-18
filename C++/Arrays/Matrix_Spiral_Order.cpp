vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> ret;
    int iw = A.size();  // window size along 1st dim
    if(iw == 0) return {};
    if(iw == 1) return A[0];
    int jw = A[0].size();  // window size along 2nd dim
    if(jw == 1) {
        for(auto v: A) ret.emplace_back(v[0]);
        return ret;
    }
    iw--;
    int i = 0, j = 0;
    while(iw > 0 || jw > 0) {  // exhaust both window sizes
        for(int k=0; k<jw; k++, j++) {  // along j: right -->
            ret.emplace_back(A[i][j]);
        }
        j--;  // inc of last iter
        jw--;  // window size --
        i++;  // move to next starting place
        if(!iw) break;  // break if cannot go down

        for(int k=0; k<iw; k++, i++) {  // along i: down
            ret.emplace_back(A[i][j]);
        }
        i--;
        iw--;
        j--;
        if(!jw) break;  // break if cannot go left

        for(int k=0; k<jw; k++, j--) {  // along i: left <--
            ret.emplace_back(A[i][j]);
        }
        j++;
        jw--;
        i--;
        if(!iw) break;  // break if cannot go up

        for(int k=0; k<iw; k++, i--) {  // along j: up
            ret.emplace_back(A[i][j]);
        }
        i++;
        iw--;
        j++;
        if(!jw) break;  // break if cannot go right
    }
    return ret;
}
