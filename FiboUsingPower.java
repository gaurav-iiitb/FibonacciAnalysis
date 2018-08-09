
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import static java.lang.System.exit;
import java.math.BigInteger;
import java.util.Scanner;

public class FiboUsingPower {
    
    public static void main(String args[])throws IOException{
        
        BigInteger m;
        
        //Taking the value of m as an input from the user
        //Can be read from a file as well
        System.out.println("Enter m");
        Scanner scan = new Scanner(System.in);
        m = scan.nextBigInteger();
        
        //Reading the value of n from a file
        //Mentioning Relative File Path in the File Constructor
        File file = new File("input.txt");
        BufferedReader br = new BufferedReader(new FileReader(file));
        String n = br.readLine();
        
        //Defining the array A 
        int A[][] = new int[][]{{1, 1},{1, 0}};
        System.out.println(power(A, n, m));
        
    }
    
    //Calculates the power A^n for base 10
    public static BigInteger power(int A[][], String n, BigInteger m){
        
        int i = n.length()-1; 
        int y[][] = new int[][]{{1,0},{0,1}};
        int n_num;
        BigInteger result;
        while(i>=0){
            
            n_num = n.charAt(i) - 48;
            y = matmul(y, pow(A, n_num));
            A = pow(A, 10);
            i--;
        }
        
        //We should note that F[0] and F[1] are 2 pre-accumalated values
        //When we are calculating F[n] we are actually finding F[n+2]
        //Thus, we need F[n-2]=F[n]-F[n-1]
        int x = (y[0][0]-y[1][0]);
        result = BigInteger.valueOf(x);
        
        if(result.compareTo(BigInteger.ZERO) > 0){
            return result;
        } else {
            //In case the value is negative add mod parameter to it
            return result.add(m);
        }
    }
    
    //Calculates A^(any number) as mentioned in the input string
    public static int[][] pow(int A[][], int n){
        
        int y[][] = new int[][]{{1,0},{0,1}};
        while(n>0) {
            if(n%2 == 1){
                y = matmul(y, A);
            }
            A = matmul(A, A);
            n = n/2;
        }
        return y;
        
    }
    
    //Matrix Multiplication Code
    public static int[][] matmul(int A[][], int B[][]){
        
        int C[][] = new int[2][2];
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                for(int k=0; k<2; k++) {
                    //Make sure to do the mod m as and when the elements are created
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j])%100;
                }
            }
        }
        return C;
    }
    
}
