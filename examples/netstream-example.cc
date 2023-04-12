#include "ns3/core-module.h"
#include "ns3/netstream-helper.h"
#include "ns3/netstream-constants.h"
#include "ns3/netstream-storage.h"
#include "ns3/netstream-socket.h"
#include "ns3/netstream-sender.h"



/**
 * \file
 *
 * Explain here what the example does.
 */

using namespace ns3;
using namespace std;



void e(){
  string source_id="C++_netstream_test";
  long time_id=0L;
   NetStreamSender stream("default","192.168.1.104",8080,false);
  string n1("node");
  for (int i = 0; i < 500; i++) {
    stringstream n1;
    n1<<i;
  stream.addNode(source_id, time_id++, n1.str());
  if (i > 0) {
    
    
    stringstream n2;
    n2<<(i-1);
    
    stringstream n3;
    n3<<(i/2);
    
    stringstream e1;
    e1<<n1.str()<<"-"<<n2.str();
    stringstream e2;
    e2<<n1.str()<<"-"<<n3.str();
    //cout<<"edge :"<<e1.str()<<endl;
    stream.addEdge(source_id, time_id++, e1.str(), n1.str(), n2.str(), false);
    stream.addEdge(source_id, time_id++, e2.str(), n1.str(), n3.str(), false);
  }
  }
}
int
main(int argc, char* argv[])
{
    bool verbose = true;

    CommandLine cmd(__FILE__);
    cmd.AddValue("verbose", "Tell application to log if true", verbose);

    cmd.Parse(argc, argv);
    cout << "hellow world" << endl;
    e();   

    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
