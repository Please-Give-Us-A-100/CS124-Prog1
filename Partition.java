
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.*;
import java.util.Random; 
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.util.Random;

public class Partition {
	public int kk(ArrayList<Integer> list) {
		int max2 = 1;
		int max1 = 0; 
		while (max2 > 0) {
			max1 = Collections.max(list); 
			int index1 = list.indexOf(max1);
			list.set(index1, 0); 
			max2 = Collections.max(list); 
			int index2 = list.indexOf(max2);
			int replace = max1 - max2; 
			list.set(index1, replace); 
			list.set(index2, 0); 
		}
		return max1; 
		



	}

	public int residue(ArrayList<Integer> list, ArrayList<Integer> soln) {
		int n = list.size(); 
		int residual = 0; 
		for (int i = 0; i < n; i++) {
			residual = residual + soln.indexOf(i)*list.indexOf(i); 
		}
		return Math.abs(residual); 
	}

	public int wasteOfTime(ArrayList<Integer> list) {
		int n = list.size(); 
		Random rand = new Random(); 
		int sum1 = 0; 
		int sum2 = 0; 
		int i, j; 
		while (list.isEmpty() == false) {
			if (n == 1) {
				double prob = Math.random();
				if (prob < .5) {
					sum1 += list.indexOf(0);
				}
				else {
					sum2 += list.indexOf(0);
				}
				list.remove(0);
			}
			else {
				i = rand.nextInt(n-1); 
				j = rand.nextInt(n-1); 
				while (i == j)  {
					j = rand.nextInt(n-1); 
				}

				// Put integer at index i in array 1 
				sum1 += list.indexOf(i); 
				// Empty spot at i in arraylist
				list.remove(i); 

				double prob = Math.random();
				if (prob < .5) {
					sum1 += list.indexOf(j);
				}
				else {
					sum2 += list.indexOf(j);
				}
				list.remove(j); 
				n = list.size(); 
			}
			// generate 2 random numbes
			// check if they are not equal 
			// if they are equal switch one of them 
			// check if both of them have value -1 
			// if either one does, then choose a different one 
		}
		int residual = Math.abs(sum2 - sum1); 
		return residual; 
	}

	public int rRand(ArrayList<Integer> list) {
		int n = list.size(); 
		ArrayList<Integer> soln1 = new ArrayList<>(); 
		for (int i = 0; i < n; i++) {
			double prob = Math.random();
			if (prob < .5)
				soln1.add(1);
			else 
				soln1.add(-1);
		}
		int soln = residue(list, soln1); 

		for (long l = 0; l < Long.MAX_VALUE; l++) {
			ArrayList<Integer> newsoln = new ArrayList<>(); 
			for (int i = 0; i < n; i++) {
			double prob = Math.random();
			if (prob < .5)
				newsoln.add(1);
			else 
				newsoln.add(-1);
			}
			int newsolution = residue(list, newsoln);
			if (newsolution < soln)
				soln = newsolution;  

			// not sure if i wanna include this yet	
			//newsoln.clear();
		}

		return soln; 

	}

	public int hillClimb(ArrayList<Integer> list) {
		return 0; 
	}

	public int simA(ArrayList<Integer> list) {
		return 0; 
	}

	public int pRRand(ArrayList<Integer> list) {
		return 0; 
	}

	public int pHillClimb(ArrayList<Integer> list) {
		return 0; 
	}

	public int pSimA(ArrayList<Integer> list) {
		return 0; 
	}

	public static void main (String [] args) throws FileNotFoundException {
		Partition p = new Partition(); 

		int alg = Integer.parseInt(args[1]); 
	    Scanner input = new Scanner(new File(args[2]));

	    ArrayList<Integer> list; 
	    list = new ArrayList<>(); 
   			while(input.hasNextInt()) {
   				list.add(input.nextInt()); 
   		}

   		int test = 0; 
   		if (alg == 0) 
   			test = p.kk(list); 
   		else if (alg == 1)
   			test = p.rRand(list); 
   		else if (alg == 2)
   			test = p.hillClimb(list); 
   		else if (alg == 3)
   			test = p.simA(list); 
   		else if (alg == 11)
   			test = p.pRRand(list);
   		else if (alg == 12)
   			test = p.pHillClimb(list);
   		else if (alg == 13)
   			test = p.pSimA(list); 
   		else 
   			System.out.println("Invalid algorithm code"); 
   		System.out.println("Test: " + test); 
		
	}
}

