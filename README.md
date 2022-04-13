# No bounty bugs

第一个bug分为四个案例MSRC选择不认,漏洞是SYSTEM服务Rpc接口函数中的越界读漏洞。由于不是内核中的越界读，并且没有返回信息，所以没有被认，最后处理的方式是直接把整个ControlDispatch中的函数加了异常处理（我不太确定是所有的函数）。    

第二个bug是一个案例MSRC选择不认，漏洞是rasapi中的整数溢出导致的堆溢出，我得到的回复是To cause the crash, one must be local on that box, and update a registry key to change the length of the data. The proof-of-concept then calls into RasSetEapUserDataW which reads the reg key and performs length calculations based on the malformed data. A crash then occurs within a subsequent memcpy. We could not find a legitimate code path that rasman svchost would encounter this issue for potential EoP. Having to set this reg key beforehand would eliminate a realistic RCE vector.  A fix for this issue will be considered in a future version of this product or service.

第三个bug是一个案例被MSRC认了提权但是被撞了，漏洞是受系统信任的自定义marshal中的整数溢出导致的越界写零漏洞.目前已分配CVE-2022-21967。

第四个bug分为两个案例（报告分为四个，两处空指针，两处越界读），该报告的中的两处空指针MSRC选择不认，漏洞通过clusport.sys中的ioctl调用触发。  

第五个bug是一个案例被认了提权但是被撞了，该漏洞通过COM组件接口调用触发，目前已发布补丁并分配CVE-2022-24547
