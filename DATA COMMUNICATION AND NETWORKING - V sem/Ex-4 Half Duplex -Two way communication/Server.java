import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class Server {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			System.out.println("Server starts.../");
			ServerSocket ss = new ServerSocket(9806);
			Socket soc = ss.accept();
//			System.out.println("Client Connected...");
			BufferedReader out = new BufferedReader(new InputStreamReader(soc.getInputStream()));
			String str = out.readLine();
			System.out.println("Clint message recived! \nClient message: "+str);
			
//			data sent to client:
			BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter Text To sent 'CLIENT' : ");
			String str1 = userInput.readLine();
			PrintWriter in = new PrintWriter(soc.getOutputStream(),true);
			in.println(str1);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

}
