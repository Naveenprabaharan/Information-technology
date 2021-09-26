import java.net.*;
import java.util.*;
import java.io.*;
public class SlideSend{
    public static void main(String a[])throws Exception{
        ServerSocket ser=new ServerSocket(6666);
        Socket s=ser.accept();
        DataInputStream din =new DataInputStream(s.getInputStream());
        DataOutputStream dout = new DataOutputStream(s.getOutputStream());
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Window Size:");
        int w = sc.nextInt();
        System.out.print("Enter the Frame Size:");
        int f = sc.nextInt();
        dout.writeUTF(Integer.toString(f));
        System.out.print("Enter data for "+f+" frames:");
        String data[] = new String[f];
        sc.nextLine();
        for(int i=0;i<f;i++){
            data[i] = sc.nextLine();
        }
        int i=0;
        while(i<f){
            if(i+w>=f){
                System.out.println("Sending "+(f-i)+" frames...");
                dout.writeUTF(Integer.toString(f-i));
                for(i=i;i<f;i++){
                    dout.writeUTF(data[i]);
                }
            }else{
                System.out.println("Sending "+w+" frames...");
                dout.writeUTF(Integer.toString(w));
                for(int j=0;j<w;j++){
                    dout.writeUTF(data[i]);
                    i++;
                }
            }
            int ack = Integer.parseInt(din.readUTF());
            System.out.println("Acknowledgement Received for "+ack+" Frames");
            i = ack;
        }
    }
}