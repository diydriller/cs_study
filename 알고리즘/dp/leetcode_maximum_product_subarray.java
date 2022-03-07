
public class leetcode_maximum_product_subarray {

    // 문제 : 배열의 부분부열의 곱의 최대값 구하기
    // 배열길이 최대값 10^4

    // 곱이기때문에 최대값은 양수 x 양수 또는 음수 x 음수가 될 수 있음
    static int maxProduct(int[] nums) {
        int len=nums.length;
        int[] min_dp=new int[len];
        int[] max_dp=new int[len];

        min_dp[0]=nums[0];
        max_dp[0]=nums[0];
        for(int i=1;i<len;i++){
            int num=nums[i];
            max_dp[i]=Math.max(num,Math.max(max_dp[i-1]*num,min_dp[i-1]*num));
            min_dp[i]=Math.min(num,Math.min(min_dp[i-1]*num,max_dp[i-1]*num));
        }

        int ans=Integer.MIN_VALUE;
        for(int i=0;i<len;i++){
            ans=Math.max(ans,max_dp[i]);
        }

        return ans;

    }

    public static void main(String[] args){

        int[] nums={2,3,-2,4};
        System.out.println(maxProduct(nums));

    }
}
