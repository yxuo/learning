<!--
TODO: continue from 13:00
-->

# Azure IaaS introduction - Webinar

Infrastructure as as Service

**Microsoft**

## Goals

* Watch the video and take relevant notes right here;
* If I have to code I put it in the same folder.

## Watch the course:

<a href="https://info.microsoft.com/ww-thankyou-introduction-to-infrastructure-as-a-service-iaas-on-azure-new.html"><img src="https://play.vidyard.com/Y81dCsiGj4cVuJZecobAP5.jpg" style="width:500px;"></a>

## Notes

###  Microsoft Cloud services:

* Microsoft 365 - OneDrive, Teams, Outlook. Team collaboration and basic cloud storage.
* Dynamic 365 - Sales, marketing, finance. A portfolio and ecosystem for business guys.
* Azure - infrastructure cloud for create your web apps etc.

### Main focuses of newbies migrating:

* :gear: Remote work models;
* :chart_with_upwards_trend: Cost efficiency &resource constraints;
* :shield: Cybersecutiry;
* :package: "Fragile" on-premisses (locally installed software) operations
* :dart: meeting surge (lots of meeting / week) demand.

Azure is basically a center of database, anything so different from other datacenters.

### Azure core services: 

* :computer: Virtual network - Optional private network (intranet), on premise (local) datacenters, NSG, user defines routes, IP addresses;
* :balance_scale: Load balancer - deliver high availability and performance yo your webapps;
* :door: Firewall - native firewall.

### Creating Azure Vnet

> VNet = Virtual Network


#### Hard way - Using PowerShell Script

> *Not discussed.*

#### Easiest way - Azure site

1. [portal.azure.com](https://portal.azure.com ) 

2. Create a resource > Networking > Virtual Network.  
   Or search `virtual network`.

   * You may find an "app" like this:

        ![azure virtual network](img/azure-vn.png)

3. Fill the textboxes;

   * In "region" field, search in [Azure geographies](https://azure.microsoft/en-us/global-infrastructure/geographies) that makes sense for your needs:

    

   > You can also see the map without an account [here](https://infrastructuremap.microsoft.com/).

    ![azure server map](img/azure-map.png)

4. IP adresses:

   * When you get a VNet space you must consider your on-pressimes networks, address spaces nwetorks.
   * Config subnets, so you can avoid collisions by overloading your tunnel.

5. Security & Tags:

   * The default settings are just ok so you don't have to config. You can jump to **Review + create**!

6. Review + create:

    > Check the information and finish!

### Storage

<table>
    <tr>
        <th>💽 Disk Storage</th>
        <th>📁 File Storage</th>
        <th>📦 Object storage</th>
    </tr>
    <tr>
        <td style="text-align:center; vertical-align:top">
            <section>Preemium</section>
            <section>Standard</section>
            <section>Ultra</section>
        </td>
        <td style="text-align:center; vertical-align:top">
            <section>Azure Files</section>
            <section>Azure NetApp Files</section>
        </td>
        <td style="text-align:center; vertical-align:top">
            <section>Azure Blobs*</section>
        </td>
    </tr>
    <tr style="text-align:center; vertical-align:top;">
        <td>
            <section>Reliable, persistent, high performing for VMs</section>
        </td>
        <td>
            <section>Lift and shift* of apps that require file shares to the cloud.</section>
        </td>
        <td>
            <section>Massively scalable and secure object storage for cloud-native workloads*.</section>
        </td>
    </tr>
</table>

* Blob - **B**inary **l**arge **ob**ject.

  * Non structured storage file.

  * A file optimized to storage large amounts of non structured data.
  
* Lift and shift - Rehosting. Make an exact copy of an web app, movint to another server storage.

* Workload (server) - amount of processing that a server will have to deal.

#### :file_folder: File Storage:

* You can use Azure Files or NetApp Files

## Source:

* [Lift and Shift - IBM](https://www.ibm.com/cloud/learn/lift-and-shift)
* [Introduction to Azure Storage - Microsoft](https://docs.microsoft.com/en-us/azure/storage/common/storage-introduction)
* [Server Workload - Suse](https://www.suse.com/suse-defines/definition/server-workload/)