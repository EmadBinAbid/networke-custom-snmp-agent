# NetworkE - A Custom SNMP Agent

NetworkE is a customized monolithic product built on top of NET-SNMP. The NetworkE engine extends the core NET-SNMP module to set up an SNMP agent along with custom enterprise OIDs on a Linux server to be monitored. 

The NetworkE engine uses C++ and bash scripts to generate customized enterprise solution to help organizations with their network management. 

# NetworkE Subscription

NetworkE is a paid subscription for its fully-featured accessibility. Apart from generic resources which are available for free, NetworkE's premium package allows an enterprise to deal with highly scalable network architectures by providing a great level of ease in network management and configuration.

## What You Can Access For Free?
NetworkE allows you to keep track of your network devices by allowing you to access:

- Current Linux OS version
- Latest signal value (latest activity that happened on the network device; events, updates, upgrades, etc)
- The disk space of /var/log directory on the network device


## Additional Subscription Benefits

The fully-featured version of NetworkE allows enterprises to customize the solution by adding any number of network parameters and access any custom information from the network device.

- Access version of not just Linux OS, but any software installed on the linux network device
- Access any value in the network device; provided that the accessing key is specified
- Access the disk space of any directory on the network device

# Requirements

To run NetworkE on your machine, you are requested to abide by the following requirements:

- Ubuntu 16.xx or 18.xx or 20.xx
- PostgreSQL 12 (https://www.postgresql.org/download/linux/ubuntu/)
- C++17

# Dependencies

- snmpd
- snmp 
- libsnmp-dev
- snmp-mibs-downloader
- libboost-all-dev 
- libpq-dev 
- libpqxx

# Setup and Configuration

## Setting up PostgreSql Database

- Please follow the steps in `./scripts/database.txt` to setup the PostgreSql database locally. Please note that failure to comply with these steps might result in application failure in its current state.

- To populate the table with some sample data, please run the script in `./scripts/database.sql`

## Running the Application

There are two ways to run NetworkE. 

### By Rewriting the Config File (Recommended)

- Run the application using `sudo ./run.sh`

### By Enabling the Program to Dynamically Run the C++ Program from snmpd.conf

- Run the application using `sudo ./run-d.sh`
- Copy the contents from `./snmpd-template.conf` into `./snmpd.conf` 
- After that, run the following command in shell to shift the default config file: `sudo cp ./snmpd.conf /etc/snmp/`default Finally, run `sudo setup.sh` to see the results 

# Points to Remember

- The application execution might take time initially depending upon the package updates. NetworkE works on latest system packages and installs/updates them upon execution.

***

# Task Specific Description

This section answers the questions that were asked in the initial task brief.

## Design

NetworkE follows an object-oriented design approach. The reason for choosing this approach over others was to take into account the processes of scalability. NetworkE system is not tightly coupled, hence, it allows the developers to scale it within the umbrella of a monolithic application architecture. Currently, there does not exist the need to shift it to the microservice arhitecture but it can surely be considered in future according to the needs and requirements. 

- `./src/main.cpp` is the program entry point. It contains the program flow and dynamically decides which sections of program need to be run depending upon the selection between `./run.sh` or `./run-d.sh`.

- `./scripts` contains all the necessary needed to run the program. Currently, it has `database.txt` and `database.sql` scripts to set up and insert sample data respectively.

- `./run.sh` compiles and runs the recommended (default) version of NetworkE.
- `./run-d.sh` compiles the dynamic version of NetworkE.
- `./snmpd-template.conf` is the config template for NET-SNMP.
- `./snmpd.conf` is the actual config file which the NET-SNMP module reads at runtime.
- `./setup.sh` does all the hard work. It installs dependencies, sets up the Postgre instance and sends the sample requests to specific object identifiers (OIDs).

Furthermore, the current NetworkE program flow in `src/main.cpp` does not build the entire tree and node structure. The code for building that exists there but is commented out. The reason for that is there does not seem the need to do for the current task assessment. The code for building information trees and nodes is written there to show that the system is not tightly coupled and can be configured in whatever way you want. The internal functionalities are complete and can be viewed in `InformationTree`, `InformationNode`, and `NetworkE` classes. The other classes such as `AgentObject`, `NetworkStatus`, and `NetworkType` inherit from the base `InformationNode` class to construct to the OID for a specific resource. Any questions? I'm sure there will be! Please feel free to contact in case of any confusions, queries, or discrepancies. 

## Testing Methodology

Overall in the entire application development, I used functional testing, acceptance testing, and design testing. This was all a manual process. I did not write any unit tests for now. 

## Breakdown of Tasks

It took all together three days (including R&D) to come up with a mini-product, NetworkE, that extends the NET-SNMP agent. The breakdown of tasks is as follows.

- `05 hrs` -> R&D about SNMP and NET-SNMP. One of the toughest tasks in the entire process.
- `07 hrs` -> Figuring out how to extend NET-SNMP to run custom programs.
- `03 hrs` -> C++ application architecture planning
- `03 hrs` -> C++ application design planning
- `10 hrs` -> C++ application implementation
- `02 hrs` -> Minor tweakings and launching the product

One of the reasons for choosing OOP design methodology was the application scalability and code resuability. The reason for choosing C++ as the product programming language was to cater to high performance and speed. C also provides high speed efficiencies but the reason for not choosing C was to avoid unfavourable circumstances of dealing with old, complex, and non-flexible OOP scenarios. Hence, C++ was the ideal choice. If there were no C++, I would have chosen Python because of its easy syntax and ever-growing support community. 

## A Better Approach

One of the better approaches could have been to use the source NET-SNMP and write code in C in the actual NET-SNMP product. This could have been a better approach and I will surely explore it more but I lost its motivation as a first approach when I planned to use OOP design methods for NetworkE. If there was more time, I'd have definitely gone into exploring it more!

Having said that, the dynamic version of NetworkE (`./run-d.sh`) also needs some improvements. Due to time constraints, I could not do them in this release, I will make those improvements in the next release.

