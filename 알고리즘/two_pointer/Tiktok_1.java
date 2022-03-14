import java.util.Arrays;

public class Tiktok_1 {

    // 문제 : 배열 2개 주어졌을때 배열의 원소가 다른 배열에 모두 속하는지 판단

    // 정렬 후 two pointer
    private static boolean isContainAllElement(int[] A, int[] B) {
        int len1=A.length,len2=B.length;
        int i=0,j=0;

        Arrays.sort(A);
        Arrays.sort(B);

        for(;j<len2;j++){
            if(i==len1) return true;
            if(A[i]==B[j]) i++;
        }
        return false;
    }

    public static void main(String[] args){
        int[] A={1,2,3};
        int[] B={5,-1,1,4,2,3};
        boolean ans=isContainAllElement(A,B);
        System.out.println(ans?"Yes":"No");
    }

}
