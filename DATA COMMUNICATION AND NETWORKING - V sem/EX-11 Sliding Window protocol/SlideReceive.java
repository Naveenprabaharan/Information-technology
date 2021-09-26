import java.net.*;
import java.util.*;
import java.io.*;
public class SlideReceive{
    public static void main(String args[])throws Exception{
        Socket s= new Socket("localhost",6666);
        DataInputStream din =new DataInputStream(s.getInputStream());
        DataOutputStream dout = new DataOutputStream(s.getOutputStream());
        Scanner sc = new Scanner(System.in);
        int f = Integer.parseInt((String)din.readUTF());
        String[] data = new String[f];
        int i=0;
        while(i<f){
            int a = Integer.parseInt((String)din.readUTF());
            for(int j=0;j<a;j++){
                data[i] = (String) din.readUTF();
                System.out.println("The Data in the "+i+" Frame:"+data[i]);
                i++;
            }
            System.out.println("Acknowledgement Sent for "+a+" Frames.");
            dout.writeUTF(Integer.toString(i));
        }
    }
}