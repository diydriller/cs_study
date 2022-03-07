
public class leetcode_container_with_most_water {

    // 문제: 선들의 높이가 담긴 배열이 주어지고 2개의 선으로 컨테이너를 만들때 가장 큰 넓이 구하기
    // 배열크기 최대값 10^4

    static int maxArea(int[] height) {
        int len=height.length;
        int s=0,e=len-1,ans=0;

        while(s<e){
            int h1=height[s];
            int h2=height[e];

            int h=Math.min(h1,h2);
            int x=e-s;

            ans=Math.max(ans,h*x);

            if(h1<h2){
                s++;
            }
            else{
                e--;
            }
        }

        return ans;
    }

    public static void main(String[] args){

        int []height={1,8,6,2,5,4,8,3,7};
        System.out.println(maxArea(height));

    }
}