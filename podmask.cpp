for (int m=0; m<(1<<n); ++m){
	for (int s=m; s >= 0; s=(s-1)&m){
		... использование s и m ...
		if (s == 0){
			break;
		}
	}
}
// O(3 ^ n)