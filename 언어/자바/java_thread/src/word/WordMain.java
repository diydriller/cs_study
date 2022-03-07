package word;

import java.awt.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.*;

public class WordMain {

    static int countWord(String s,String p){
        int idx1=0,idx2=-1;
        int cnt=0;

        while((idx2=s.indexOf(p,idx1))!=-1){
            cnt++;
            idx1=idx2+p.length();
        }
        return cnt;
    }

    public static void main(String[] args) throws Exception {
        List<Path> paths= Arrays.asList(
                Paths.get("./java_thread/src/word/file/file1.txt"),
                Paths.get("./java_thread/src/word/file/file2.txt")
        );

        String word="기온";
        List<Callable<Integer>> tasks=new ArrayList<>();
        for(Path p:paths){
            tasks.add(
                    ()->{
                        int cnt=0;
                        List<String> lines=Files.readAllLines(p);
                        for(String line:lines){
                            cnt+=countWord(line,word);
                        }
                        return cnt;
                    }
            );
        }
        ExecutorService executor= Executors.newFixedThreadPool(2);
        List<Future<Integer>> results=executor.invokeAll(tasks);

        int total=0;
        for(Future<Integer> result:results){
            total+=result.get();
        }

        System.out.println(total);

    }
}
