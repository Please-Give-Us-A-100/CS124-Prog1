
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections; 
import java.util.*;
import java.util.Random; 
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.util.Random;


public class Partition {
	// Karmarkar-Karp Algorithm 
	public long kk(ArrayList<Long> list) {
		long max2 = 1;
		long max1 = 0; 
		while (max2 > 0) {
			max1 = Collections.max(list); 
			int index1 = list.indexOf(max1);
			list.set(index1, Long.valueOf(0)); 
			max2 = Collections.max(list); 
			int index2 = list.indexOf(max2);
			long replace = max1 - max2; 
			list.set(index1, replace); 
			list.set(index2, Long.valueOf(0)); 
		}
		return max1; 
	}

	// Residue algorithm -- calculates residual given a list and a solution
	// set based on the solution set partitioning. 
	public long residue(ArrayList<Long> list, ArrayList<Long> soln) {
		int n = list.size(); 
		long residual = 0; 
		for (int i = 0; i < n; i++) {
			residual = residual + soln.get(i)*list.get(i); 
		}

		return Math.abs(residual); 
	}

	public ArrayList<Long> generateSoln(ArrayList<Long> list) {
		int n = list.size(); 
		ArrayList<Long> soln1 = new ArrayList<>(); 
		for (long i = 0; i < n; i++) {
			double prob = Math.random();
			if (prob <= .5)
				soln1.add(Long.valueOf(1));
			else 
				soln1.add(Long.valueOf(-1));
		}
		
		return soln1; 
	}

	
	// Repeated Random Algorithm
	public long rRand(ArrayList<Long> list) {
		int n = list.size(); 

		long soln = residue(list, generateSoln(list)); 
		int max_iteri = 25000; 

		for (long l = 0; l < max_iteri; l++) {
			// Generates random solution
			ArrayList<Long> newsoln = new ArrayList<>(); 
			for (int i = 0; i < n; i++) {
				double prob = Math.random();
				if (prob <= .5)
					newsoln.add(Long.valueOf(1));
				else 
					newsoln.add(Long.valueOf(-1));
			}
			long newsolution = residue(list, newsoln);
			if (newsolution < soln)
				soln = newsolution;  
		}

		return soln; 

	}
	// Hill Climbing Algorithm
	public long hillClimb(ArrayList<Long> list) {
		long n = list.size(); 
		ArrayList<Long> soln1 = generateSoln(list);
		long res = residue(list, soln1); 

		long max_iteri = 25000; 
		for (int l = 0; l < max_iteri; l++) {
			ArrayList<Long> newsoln = soln1;
			// Change a random element of soln to generate a "neighbor"
			int index = (int)(Math.random() * n);
			long val = newsoln.get(index);
			// Chnages sign of element at index  
			newsoln.set(index, val*Long.valueOf(-1)); 
			
			long newresidue = residue(list, newsoln); 
			if (newresidue < res) {
				res = newresidue; 
				soln1 = newsoln; 
			}
		}
		return res; 
	}

	// Simulated Annealing Algorithm
	public long simA(ArrayList<Long> list) {
		long n = list.size();
		ArrayList<Long> startSoln = generateSoln(list); 
		ArrayList<Long> endSoln = new ArrayList<Long>(startSoln);
		long max_iteri = 1300000; 

		for (int i = 1; i < max_iteri; i++) {
			ArrayList<Long> newSoln = new ArrayList<Long>(startSoln);
			// Choose a random index to change the value of
			int index = (int)(Math.random() * n);
			long val = newSoln.get(index);
			// Changes sign of element at index to create neigbor
			newSoln.set(index, val*Long.valueOf(-1));
			
			// Generate probability
			double prob = Math.exp(-(double)(residue(list, newSoln) - residue(list, startSoln))/(Math.pow(10.0, 10.0)*Math.pow(0.8, Math.floor((double)i/300.0))));
			double determine = Math.random(); 
			if (residue(list, newSoln) < residue(list, startSoln)) {
				startSoln = (ArrayList<Long>)newSoln.clone();
			}
			else if (prob > determine) {
				startSoln = (ArrayList<Long>)newSoln.clone();
			}
			if (residue(list, startSoln) < residue(list, endSoln)) {
				endSoln = (ArrayList<Long>)startSoln.clone();
			}
		}
		return residue(list, endSoln);
	}

	// Pre-partition algorithm, takes in a list and a pre-partitioning of
	// the list and outputs a new list based on the pre-partitioning. 
	public ArrayList<Long> prePartition(ArrayList<Long> listA, ArrayList<Long> partitionA) {
		int n = listA.size(); 
		for (int i = 0; i < n; i++) {
			long setS = partitionA.get(i); 
			if (setS != -1) {
				long startval = listA.get(i); 
				partitionA.set(i, (long)-1); 
				for (int j = i+1; j < n; j++) {
					if (partitionA.get(j) == setS) {
						startval += listA.get(j); 
						partitionA.set(j, (long)-1); 
						listA.set(j, (long)0); 
					} 
				}
				listA.set(i, startval);
			}		
		}
		return listA; 
	}
	
	// Pre-partitioned Repeated Random Algorithm
	public long pRRand(ArrayList<Long> list) {
		int n = list.size(); 
		// Create random pre-partitioning
		ArrayList<Long> partition = new ArrayList<>(); 
		for (int i = 0; i < n; i++){
			int setNumber = (int)(Math.random() * n); 
			partition.add(Long.valueOf(setNumber));
		} 
		long max_iteri = 25000;

		// Create copies of lists. Not sure why, but prePartition
		// algorithm messes destroys lits after use.
		ArrayList<Long> partitioncopy = new ArrayList<Long>(partition);
		ArrayList<Long> listcopy = new ArrayList<Long>(list);
		ArrayList<Long> partitionedlist = prePartition(listcopy, partitioncopy);
		long res = kk(partitionedlist);

		for (long l = 0; l < max_iteri; l++) {
			ArrayList<Long> partition2 = new ArrayList<>(); 
			for (int i = 0; i < n; i++){
				int setNumber = (int)(Math.random() * n); 
				partition2.add(Long.valueOf(setNumber));
			} 

			// Create copies of lists. Not sure why, but prePartition
			// algorithm messes destroys lits after use.
			ArrayList<Long> partition2copy = new ArrayList<Long>(partition2);
			ArrayList<Long> listcopy2 = new ArrayList<Long>(list);
			ArrayList<Long> newpartlist = prePartition(listcopy2, partition2copy);
			long newres = kk(newpartlist);
	
			if (newres < res){
				res = newres; 
			}

		}


		return res; 
	}
	// Pre-partitioned Hill Climb Algorithm
	public long pHillClimb(ArrayList<Long> list) {
		int n = list.size(); 

		// Create random pre-partitioning
		ArrayList<Long> partition = new ArrayList<>(); 
		for (int i = 0; i < n; i++){
			int setNumber = (int)(Math.random() * n); 
			partition.add(Long.valueOf(setNumber));
		} 
		long max_iteri = 25000;
		
		// Create copies of lists. Not sure why, but prePartition
		// algorithm messes destroys lits after use.
		ArrayList<Long> partitioncopy = new ArrayList<Long>(partition);
		ArrayList<Long> listcopy = new ArrayList<Long>(list);
		ArrayList<Long> partitionedlist = prePartition(listcopy, partitioncopy);
		long res = kk(partitionedlist);
		for (int l = 0; l < max_iteri; l++) {
			// Create neighbor
			ArrayList<Long> partition2 = new ArrayList<Long>(partition);

			// Generate random index
			int index = (int)(Math.random() * n);
			long setNumber = (long)(Math.random() * n);
			// Changes partitioning of one element, creating a neighbor.  
			partition2.set(index, setNumber); 	
	
			// Create copies of lists. Not sure why, but prePartition
			// algorithm messes destroys lits after use.
			ArrayList<Long> partition2copy = new ArrayList<Long>(partition2);
			ArrayList<Long> listcopy2 = new ArrayList<Long>(list);
			ArrayList<Long> newlist = prePartition(listcopy2, partition2copy);

			long newresidue = kk(newlist); 
			if (newresidue < res) {
				res = newresidue; 
			}


		}
		return res;
	}

	// Pre-partitioned Simulated Annealing Algorithm
	public long pSimA(ArrayList<Long> list) {
		int n = list.size(); 
		// Creates random pre-partitioning. 
		ArrayList<Long> partition = new ArrayList<>(); 
		for (int i = 0; i < n; i++){
			int setNumber = (int)(Math.random() * n); 
			partition.add(Long.valueOf(setNumber));
		} 
		long max_iteri = 25000;

		// Create copies of lists. Not sure why, but prePartition
		// algorithm messes destroys lits after use. 
		ArrayList<Long> partitioncopy = new ArrayList<Long>(partition);
		ArrayList<Long> listcopy = new ArrayList<Long>(list);
		ArrayList<Long> partitionedlist = prePartition(listcopy, partitioncopy);
		long res = kk(partitionedlist);
		long rescopy = res; 
		
		for (int l = 0; l < max_iteri; l++) {
			ArrayList<Long> partition2 = new ArrayList<Long>(partition);
			int index = (int)(Math.random() * n);
			long setNumber = (long)(Math.random() * n);
			// Changes partitioning of one element, creating a neighbor.   
			partition2.set(index, setNumber); 

			// Create copies of lists. Not sure why, but prePartition
			// algorithm messes destroys lits after use. 
			ArrayList<Long> partition2copy = new ArrayList<Long>(partition2);
			ArrayList<Long> listcopy2 = new ArrayList<Long>(list);
			ArrayList<Long> newlist = prePartition(listcopy2, partition2copy);
			long newresidue = kk(newlist);

			// Probability that we move to less optimal 
			double prob = Math.exp(-(double)(newresidue - res)/(Math.pow(10.0, 10.0)*Math.pow(0.8, Math.floor((double)l/300.0))));
			double determine = Math.random(); 
			if (newresidue < res) {
				res = newresidue; 
			}
			else if (prob > determine) {
				res = newresidue; 
			}
			if (res < rescopy) {
				rescopy = res; 
			}
		}
		return rescopy;
	}

		// Used for Task #4 on programming assignment. 
		public void test() {
		long kkRes = 0;
		long rRRes = 0;
		long hCRes = 0;
		long sARes = 0;
		long prRRes = 0;
		long phCRes = 0;
		long psARes = 0;

		// Karmarkar Karp
		long kkST = System.nanoTime(); 
		for (int i = 0; i < 100; i++) {
			
			ArrayList<Long> tester = new ArrayList<Long> (); 
			for (int j = 0; j < 100; j++) {
				long val = (long) (Math.random() * Math.pow(10.0, 12.0)); 
				tester.add(val); 
			}

			kkRes += kk(tester); 
			
		}
		long kkET = System.nanoTime(); 
		System.out.println("kk avg: " + kkRes/100);
		System.out.println("kk elapsed time: " + (kkET - kkST));
	
		//Repeated Random 
		long rrST = System.nanoTime(); 
		for (int i = 0; i < 100; i++) {
			
			ArrayList<Long> tester = new ArrayList<Long> (); 
			for (int j = 0; j < 100; j++) {
				long val = (long) (Math.random() * Math.pow(10.0, 12.0)); 
				tester.add(val); 
			}

			rRRes += rRand(tester); 
			
		}
		long rrET = System.nanoTime(); 
		System.out.println("repeated random avg: " + rRRes/100); 
		System.out.println("rrand elapsed time: " + (rrET - rrST));

		// Pre-Partitioned Repeated Random 
		long prrST = System.nanoTime(); 
		for (int i = 0; i < 100; i++) {
			
			ArrayList<Long> tester = new ArrayList<Long> (); 
			for (int j = 0; j < 100; j++) {
				long val = (long) (Math.random() * Math.pow(10.0, 12.0)); 
				tester.add(val); 
			}

			prRRes += pRRand(tester); 		
		}
		long prrET = System.nanoTime(); 
		System.out.println("pre-part repeated random avg: " + prRRes/100); 
		System.out.println("pre-part rrand elapsed time: " + (prrET - prrST));
		
		// Hill Climb 
		long hcST = System.nanoTime(); 
		for (int i = 0; i < 100; i++) {
			
			ArrayList<Long> tester = new ArrayList<Long> (); 
			for (int j = 0; j < 100; j++) {
				long val = (long) (Math.random() * Math.pow(10.0, 12.0)); 
				tester.add(val); 
			}

			hCRes +=  hillClimb(tester);		
		}
		long hcET = System.nanoTime(); 
		System.out.println("hill climb avg: " + hCRes/100);
		System.out.println("hill climb elapsed time: " + (hcET - hcST));

		// Pre-partitioned hill clumb 
		long phcST = System.nanoTime(); 
		for (int i = 0; i < 100; i++) {
			
			ArrayList<Long> tester = new ArrayList<Long> (); 
			for (int j = 0; j < 100; j++) {
				long val = (long) (Math.random() * Math.pow(10.0, 12.0)); 
				tester.add(val); 
			}

			phCRes += pHillClimb(tester);		
		}
		long phcET = System.nanoTime(); 
		System.out.println("pre-part hill climb avg: " + phCRes/100);
		System.out.println("pre-part hill climb elapsed time: " + (phcET - phcST));

		// Simulated Annealing 
		long saST = System.nanoTime(); 
		for (int i = 0; i < 100; i++) {
			
			ArrayList<Long> tester = new ArrayList<Long> (); 
			for (int j = 0; j < 100; j++) {
				long val = (long) (Math.random() * Math.pow(10.0, 12.0)); 
				tester.add(val); 
			}

			sARes += simA(tester);		
		}
		long saET = System.nanoTime(); 
		System.out.println("sim annealing avg: " + sARes/100); 
		System.out.println("sim annealing hill climb elapsed time: " + (saET - saST));

		// Pre-Partitioned Simulated Annealing 
		long psaST = System.nanoTime(); 
		for (int i = 0; i < 100; i++) {
			
			ArrayList<Long> tester = new ArrayList<Long> (); 
			for (int j = 0; j < 100; j++) {
				long val = (long) (Math.random() * Math.pow(10.0, 12.0)); 
				tester.add(val); 
			}

			psARes += pSimA(tester); 		
		}
		long psaET = System.nanoTime(); 
		System.out.println("pre-part sim annealing avg: " + psARes/100);  
		System.out.println("pre-part sim annealing hill climb elapsed time: " + (psaET - psaST));	
	}

	public static void main (String [] args) throws FileNotFoundException {
		Partition p = new Partition(); 

		long alg = Long.parseLong(args[1]); 
	    Scanner input = new Scanner(new File(args[2]));

	    ArrayList<Long> list; 
	    list = new ArrayList<>(); 
   			while(input.hasNextLong()) {
   				list.add(input.nextLong()); 
   		}

   		long test = 0; 
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
   		//else 
   			//System.out.println("Invalid algorithm code"); 
   		System.out.println(test); 
   		//p.test(); 	
	}
}

