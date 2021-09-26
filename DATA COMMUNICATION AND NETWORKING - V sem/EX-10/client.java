import java.io.*;
import java.net.*;
import java.util.*;
public class client {
 public static void main(String[] args) throws Exception{
 //Initialize socket
 do{
     Scanner sc = new Scanner(System.in);
     System.out.println("Enter the Choice 1.Send file 2.exit");
        int choice = sc.nextInt();
        Socket socket = new Socket(InetAddress.getByName("localhost"), 5000);

        DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
        dos.writeUTF(Integer.toString(choice));
        switch (choice) {
            case 1:
            {
            System.out.println("Enter the file Name:");
            String fileName=sc.next();
            File file = new File(fileName);
            try {
            FileInputStream fis = new FileInputStream(file);
            BufferedInputStream bis = new BufferedInputStream(fis);
            //Get socket's output stream
            OutputStream os = socket.getOutputStream();
            //Read File Contents into contents array
            byte[] contents;
            long fileLength = file.length();
            long current = 0;
            long start = System.nanoTime();
            while(current!=fileLength){
            int size = 10000;
            if(fileLength - current >= size)
            current += size;
            else{
            size = (int)(fileLength - current);
            current = fileLength;
            }
            contents = new byte[size];
            bis.read(contents, 0, size);
            os.write(contents);
            }
            os.flush();
            //File transfer done. Close the socket connection!
            socket.close();
            
            System.out.println("File sent succesfully!");
            }
           catch(Exception ex) {
               ex.printStackTrace();
           }
          break;
        }
            case 2:
            System.exit(1);
            break;
        }
        
       }while(true);
       
 }

 
}