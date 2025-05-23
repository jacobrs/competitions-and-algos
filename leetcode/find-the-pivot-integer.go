func pivotInteger(n int) int {
    if ( n == 1 ) {
        return 1;
    }
    
    i := 1;
    j := n;
    lh_sum := 1;
    rh_sum := n;

    for {
        if ( i > j ) {
            return -1;
        }

        if ( i == j && lh_sum == rh_sum ) {
            return i;
        }

        if ( lh_sum < rh_sum ) {
            i++;
            lh_sum += i;
        } else if ( lh_sum > rh_sum ) {
            j--;
            rh_sum += j;
        } else {
            i++;
            lh_sum += i;
            j--;
            rh_sum += j;
        }
    }
}
