package backtracking;

import java.util.ArrayList;
import java.util.List;


public class Tiktok_2 {

    // 문제 : *는 A또는 B를 나타낼 수 있고 A , B로만 이루어진 문자열이 주어졌을때 모든 경우의 수 출력

    // 부분집합을 backtracking으로 구하기
    static void dfs(List<Integer> wildIdxList, List<String> ans, int d, StringBuilder tempString){

        int len=wildIdxList.size();
        if(d==len){
            ans.add(tempString.toString());
            return;
        }

        int wildIdx=wildIdxList.get(d);
        tempString.setCharAt(wildIdx,'A');
        dfs(wildIdxList,ans,d+1,tempString);
        tempString.setCharAt(wildIdx,'B');
        dfs(wildIdxList,ans,d+1,tempString);

    }

    static List<String> findAllComb(String pattern){
        List<Integer> wildIdxList=new ArrayList<>();
        int len=pattern.length();
        for(int i=0;i<len;i++){
            char ch=pattern.charAt(i);
            if(ch=='*'){
                wildIdxList.add(i);
            }
        }

        StringBuilder tempString=new StringBuilder(pattern);
        List<String> ans=new ArrayList<>();
        dfs(wildIdxList,ans,0,tempString);

        return ans;
    }


    public static void main(String[] args){
        String pattern="A***B";
        List<String> ans=findAllComb(pattern);
        for(String el:ans){
            System.out.println(el);
        }

    }
}
