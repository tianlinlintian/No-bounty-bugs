# Bugs-that-are-not-vulnerabilities-

第一个bug是SYSTEM服务中的越界读，由于不是内核中的越界读，所以没有被认，后来偷偷的把整个ControlDispatch加了个异常处理。。。早知道不报了。    

第二个bug回复是To cause the crash, one must be local on that box, and update a registry key to change the length of the data. The proof-of-concept then calls into RasSetEapUserDataW which reads the reg key and performs length calculations based on the malformed data. A crash then occurs within a subsequent memcpy. We could not find a legitimate code path that rasman svchost would encounter this issue for potential EoP. Having to set this reg key beforehand would eliminate a realistic RCE vector.  A fix for this issue will be considered in a future version of this product or service.
