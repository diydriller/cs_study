public class leetcode_find_minimum_in_rotated_sorted_array {

    // 문제 : 오른쪽으로 회전된 오름차순 배열에서 최소값을 O(log n)으로 찾기

    static int findMin(int[] nums) {

        int len=nums.length;
        int l=0,r=len-1;
        int ans=Integer.MAX_VALUE;
        while(l<=r){
            int m=(l+r)/2;
            int mv=nums[m],mr=nums[r];

            if(mv>mr){
                l=m+1;
            }
            else{
                r=m-1;
            }
            ans=Math.min(ans,mv);
        }

        return ans;
    }

    public static void main(String[] args){

        int[] nums={3,4,5,1,2};
        System.out.println(findMin(nums));
    }
}

