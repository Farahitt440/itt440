import java.io.*;
import java.net.*;

public class Server
{	public statis void main(String[] args) throws Exception
	{	Server myServ = new Server();
		myServ.run();
	}
	
	public void run() throws Exception
	{ ServerSocket mySS = new ServerSocker(9999);
	 Socket SS_accept = mySS.accept();
	 
	Bufferedreader = new BufferedReader(new InputStreamReader
			(SS_accept.getInputStream())	);
	
	String temp = SS_BF.readLine();
	System.out.println(temp); 
	
	if(temp!=null){
	PrintStream SSPS = new PrintStream(SS_accept.getOutputStream()); 
	SSPS.println("Got something");
	}
}
