package week1.binarySearch;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class BinarySearch6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double[] gesStations = {0, 3, 5.4, 7.8}; 
		System.out.println(getMaxDistance(gesStations, 10000));
		System.out.println(getMaxDistance2(gesStations, 10000));
	}
	
	// input: [0, 3, 5.4], k = 3
	// output should be [0, 1, 2, 3, 4,2, 5.4], maximum distance = 1.2
	// Binary algorithm:
	//           ---------Left/T---------|---------Right/F---------	
	// distance: 0----------1---------1.1|1.2---------2-----------3
	// my_k = Math.ceil(pair_distance / cur_max_distance) - 1
	// which means the least number of new gas stations we need to build between gas station A and B to 
	// maintain the largest distance among any new pairs between A and B to be less than our current max distance.
	// let's say if cur_max_distance = 1
	// [0, 3] we need to build CEIL[(3 / 1)] - 1 = 2 gas stations between 0 and 3
	// [3, 5.4] we need to build CEIL[(5.4 - 3) / 1] - 1 = 2 gas stations between 3 and 5.4
	// which means in total we need 4 gas stations to be built in order to make their largest pair distance at most 1
	// according to the above formula, we have corresponding k values to the distances:
	// distance: 0----------1-----------1.1|1.2---------2-----------3
	// k       : INFI-------4-------------4|3-----------2-----------0
	//           ---------my_k > k---------|-------my_k <= k---------	
	//           ----------Left/T----------|---------Right/F---------	
	// so we need to return the first element on the right side
	public static double getMaxDistance(double[] gesStations, int k){
		int n = gesStations.length;
		Arrays.sort(gesStations);
		
		//initialize l and r, which are 0 and the original max pair distance, respectively.
		double l = 0;
		double r = 0;
		double[] dists = new double[n - 1];
		for(int i = 0; i < n - 1; i++){
			dists[i] = gesStations[i + 1] - gesStations[i];
			r = Math.max(dists[i], r);
		}
		
		while(l + 1e-8 < r){
			double m = (r - l) / 2 + l;
			if(calculateMyK(m, dists) > k) l = m;
			else r = m;
		}
		return l;
	}

	// calculate my k value based on the above formula;
	private static int calculateMyK(double m, double[] dists) {
		int my_k = 0;
		for(double dist : dists){
			my_k += Math.ceil(dist / m) -1;
		}
		return my_k;
	}
	
	//dfs with memorization
	private static Double[][] memo;
	public static double getMaxDistance2(double[] gesStations, int k){
		int n = gesStations.length;
		Arrays.sort(gesStations);
		
		List<Double> dists = new ArrayList<>();
		for(int i = 0; i < n - 1; i++){
			dists.add(gesStations[i + 1] - gesStations[i]);
		}
		
		Collections.sort(dists, (a, b)->{return (int) (b - a);});
		memo = new Double[k + 1][n + 1];
		return dfs(dists, dists.size(), k, 0, Integer.MAX_VALUE);
	}
	
	public static double dfs(List<Double> dists, int n, int k, int sp, int prevCut){
		if(sp == n - 1 || k == 0) return dists.get(sp) / (k + 1);
		if(memo[k][sp] != null)
			return memo[k][sp];
		double min = dists.get(sp);
		for(int j = 0; j <= k && j <= prevCut; j++){
			min = Math.min(min, Math.max(dists.get(sp) / (j + 1), dfs(dists, n, k - j, sp + 1, j)));
		}
		memo[k][sp] = min;
		return min;
	}
}

