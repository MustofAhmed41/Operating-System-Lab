/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumerassignment;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author USER
 */
public class ProducerConsumerAssignment {
    int totalSize = 7;
    Semaphore mutex = new Semaphore(1);
    Semaphore full = new Semaphore(0);
    Semaphore empty = new Semaphore(totalSize);
    
    Random rand = new Random();    
    Queue<Integer> q = new LinkedList<>();
        
    public  void producer(){
        while(true){            
            try {
                empty.acquire();
                mutex.acquire();
                int item = rand.nextInt(1000);
                q.add(item);
                System.out.println(Thread.currentThread().getName() + " : Data " + item + " is inserted in the buffer");
                System.out.println("Empty : " + (totalSize-q.size()));
                System.out.println("Full : " + q.size());
                mutex.release();
                full.release();
            } catch (InterruptedException ex) {
                Logger.getLogger(ProducerConsumerAssignment.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    public  void consumer(){
        while(true){
            try {
                full.acquire();
                mutex.acquire();
                int consumed_item = q.remove();
                System.out.println(Thread.currentThread().getName() + " : Consumed Data " + consumed_item + " from the buffer");
                System.out.println("Empty : " + (totalSize-q.size()));
                System.out.println("Full : " + q.size());
                mutex.release();
                empty.release();
            } catch (InterruptedException ex) {
                Logger.getLogger(ProducerConsumerAssignment.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
    }

    class Producer implements Runnable {
        @Override
        public void run() {        
            producer();     
        }
    }
    
    class Consumer implements Runnable {
        @Override
        public void run() {               
            consumer();          
        }
    }
    
    public static int producer = 0;
    public static int consumer = 0;
    
    public static void createProducer(ProducerConsumerAssignment pc){
        Producer p1 = pc.new Producer();
        Thread t1 = new Thread(p1);
        t1.setName("Producer " + ++producer);
        t1.start();
    }
    
    public static void createConsumer(ProducerConsumerAssignment pc){
        Consumer c1 = pc.new Consumer();
        Thread t1 = new Thread(c1);
        t1.setName("Consumer " + ++consumer);
        t1.start();
    }
    
    public static void startProgram(int pro, int con, ProducerConsumerAssignment pc ){
        for(int i = 0 ; i < pro; i++){
            createProducer(pc);
        }
         for(int i = 0 ; i < con; i++){
            createConsumer(pc);
        }
    }
    
    public static void main(String[] args) {
        ProducerConsumerAssignment pc = new ProducerConsumerAssignment();
        int producer = 5;
        int consumer = 5;
        startProgram(producer,consumer,pc);
    }
    
}
