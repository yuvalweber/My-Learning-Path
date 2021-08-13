# Table of Contents
- [terms](#terms)
- [commands](#commands)
- [structures](#structures)

<br>
<br>

# terms
<b>AID</b> – APPLICATION IDENTIFIER  
<b>AFL</b> – APPLICATION FILE LOCATOR  
<b>APDU</b> – APPLICATION PROTOCOL DATA UNIT  
<b>ATR</b>  - ANSWER TO RESET  
<b>BER</b> – BASIC ENCODING RULES  
<b>CDO</b>L – CARD RISK MANAGEMENT DATA OBJECT LIST  
<b>CVM</b> – CARD VERIFICATION METHOD  
<b>DF </b>– DEDICATED FILE  
<b>DOL</b> – DATA OBJECT LIST  
<b>ICC</b> – INTERGATED CIRCUIT CARD  
<b>CLA</b> – CLASS BYTE  
<b>INS</b> – INSTRUCTION BYTE  
<b>PAN</b> – PRIMARY ACCOUNT NUMBER  
<b>PDOL</b> – PROCESSING OPTION DATA OBJECT LIST  
<b>PSE</b> – PAYMENT SYSTEM ENVIRONMENT  
<b>PTS</b> – PROTOCOL TYPE SELECTION  
<b>Xx </b>– ANY VALUE  
<b>T=0</b> – CHARACTER PROTOCOL  
<b>T=1</b> – BLOCK PROTOCOL  

<br>
<br>

# commands
1) select file command.

![alt text](./images/select.png)
![alt text](./images/select1.png)

<br>

2) read records command.

![alt text](./images/recordRead.png)

<br>

3) application unblock

![alt text](./images/unblock.png)

<br>

4) external authenticate

![alt text](./images/extAuth.png)

<br>

5) generate AC  
<b>The GENERATE AC command sends transaction-related data to the ICC, which computes and returns a cryptogram.</b>

![alt text](./images/AcCryptoTypes.png)
![alt text](./images/GenAc.png)
![alt text](./images/GenAc1.png)

<br>

6) get challenge

![alt text](./images/GetChallenge.png)

<br>

7) get data

![alt text](./images/GetData.png)

<br>

8) get processing options

![alt text](./images/gpo.png)
![alt text](./images/DataField.png)

<br>

9) internal authenticate

![alt text](./images/IntAuth.png)

<br>

10) pin change or unblock

![alt text](./images/pinUn.png)

<br>

11) verify

![alt text](./images/verify.png)
![alt text](./images/verify2.png)
![alt text](./images/pinText.png)

<br>
<br>

# structures

![alt text](./images/structure2.png)

<br>

![alt text](./images/structure1.png)

<br>

![alt text](./images/structure3.png)
