package prime;

import java.util.ArrayList;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.List;

public class PrimeMain {

    // 멀티 스레드 사용 , synchronized 사용해서 동기화
    static void multiThreadUsingSynchronized(int threadCount) throws Exception {

        long start = System.currentTimeMillis();

        Prime prime=new Prime();
        List<PrimeThread> threadList=new ArrayList<>();

        for(int i=0;i<threadCount;i++){
            threadList.add(new PrimeThread(prime));
        }
        for(PrimeThread t:threadList){
            t.start();
        }
        for(PrimeThread t:threadList){
            t.join();
        }

        long end = System.currentTimeMillis();
        System.out.println("1. synchronized multi thread is used");
        System.out.println("prime cnt is "+prime.getPrimeCnt());
        System.out.println("time took "+(end-start));

    }

    // 싱글 스레드 사용
    static void singleThread(){

        long start = System.currentTimeMillis();
        int cnt=0;
        for(int num = 1; num<= PrimeUtil.num; num++){

            if(PrimeUtil.isPrime(num)){
                cnt++;
            }
        }

        long end = System.currentTimeMillis();
        System.out.println("2. single thread is used");
        System.out.println("prime cnt is "+cnt);
        System.out.println("time took "+(end-start));
    }

    // 멀티 스레드 사용 , atomic 사용해서 동기화
    static void multiThreadUsingAtomic(int threadCount) throws Exception {

        long start = System.currentTimeMillis();

        ExecutorService service= Executors.newFixedThreadPool(threadCount);

        AtomicInteger integer = new AtomicInteger();
        CountDownLatch latch = new CountDownLatch(PrimeUtil.num);
        AtomicInteger cnt = new AtomicInteger();


        while(true) {
            int num = integer.incrementAndGet();
            if (num > PrimeUtil.num) break;

            service.execute(() -> {

                if(PrimeUtil.isPrime(num)){
                    cnt.incrementAndGet();
                }

                latch.countDown();
            });

        }
        latch.await();
        service.shutdown();


        long end = System.currentTimeMillis();
        System.out.println("3. atomic multi thread is used");
        System.out.println("prime cnt is "+cnt);
        System.out.println("time took "+(end-start));
    }


    public static void main(String[] arg) throws Exception {

        int threadCount=8;

        multiThreadUsingSynchronized(threadCount);
        singleThread();
        multiThreadUsingAtomic(threadCount);
    }



}
