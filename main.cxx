#include <iostream>
using namespace std;
#include <unistd.h>


#include <boost/compute/system.hpp>
void PrintDevices() {



  std::vector<boost::compute::platform> platforms =
      boost::compute::system::platforms();

  for (size_t i = 0; i < platforms.size(); i++) {
    const boost::compute::platform &platform = platforms[i];
    std::cout<<"Platform = "<<platform.name()<<"\n";


    std::vector<boost::compute::device> devices = platform.devices();
    for (size_t j = 0; j < devices.size(); j++) {
      const boost::compute::device &device = devices[j];

      std::string type;
      if (device.type() & boost::compute::device::gpu)
        type = "GPU Device";
      else if (device.type() & boost::compute::device::cpu)
        type = "CPU Device";
      else if (device.type() & boost::compute::device::accelerator)
        type = "Accelerator Device";
      else
        type = "Unknown Device";
    std::cout<<"type = "<<device.name()<<"\n";
    }
  }
    std::cout<<"Using device  = "<<boost::compute::system::default_device().name()<<"\n";

}
#include <boost/compute.hpp>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    int N=atoi(argv[1]);
    PrintDevices();
    std::vector<boost::compute::vector<boost::compute::double4_> > mas;
    for(int i=0;i<30;i++)
    {
        std::cout<<"Iskiriame masyva i="<<i<<"\n";

    boost::compute::vector<boost::compute::double4_> device_vector;
    mas.push_back(device_vector);
    std::cout<<"Pradedame isskirti\n";
    mas[i].resize(N);
    boost::compute::double4_ t;
    t[0]=1;
    t[1]=2;
    t[2]=3;
    t[3]=4;
    boost::compute::fill(mas[i].begin(),mas[i].end(),t);
    std::cout<<"Isskyrimas baigesi\n";
    sleep(5);
    cout << "Hello World!" << endl;
    }
    std::cout<<mas[9][10];
    return 0;
}
