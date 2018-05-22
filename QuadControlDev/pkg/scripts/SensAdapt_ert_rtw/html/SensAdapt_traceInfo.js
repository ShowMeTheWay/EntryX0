function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Bus
Creator */
	this.urlHashMap["SensAdapt:43"] = "SensAdapt.c:71";
	/* <Root>/Pulse
Generator */
	this.urlHashMap["SensAdapt:34"] = "SensAdapt.c:44,53,115&SensAdapt.h:36";
	/* <Root>/Pulse
Generator1 */
	this.urlHashMap["SensAdapt:38"] = "SensAdapt.c:33,42,112&SensAdapt.h:34";
	/* <Root>/Sine Wave */
	this.urlHashMap["SensAdapt:32"] = "SensAdapt.c:75,93,99&SensAdapt.h:35";
	/* <Root>/Unit Delay */
	this.urlHashMap["SensAdapt:48"] = "SensAdapt.c:30,70&SensAdapt.h:32";
	/* <S1>/Out */
	this.urlHashMap["SensAdapt:33:3"] = "msg=rtwMsg_reducedBlock&block=SensAdapt/Repeating%20Sequence%20Stair1/Out";
	/* <S1>/Output */
	this.urlHashMap["SensAdapt:33:4"] = "SensAdapt.c:74";
	/* <S1>/Vector */
	this.urlHashMap["SensAdapt:33:5"] = "SensAdapt.c:72&SensAdapt.h:43&SensAdapt_data.c:23";
	/* <S2>/Discrete
Transfer Fcn */
	this.urlHashMap["SensAdapt:35"] = "SensAdapt.c:73,86&SensAdapt.h:33";
	/* <S3>/Data Type
Propagation */
	this.urlHashMap["SensAdapt:33:2:1"] = "msg=rtwMsg_reducedBlock&block=SensAdapt/Repeating%20Sequence%20Stair1/LimitedCounter/Data%20Type%20Propagation";
	/* <S3>/Output */
	this.urlHashMap["SensAdapt:33:2:4"] = "SensAdapt.c:57,76,90&SensAdapt.h:37";
	/* <S4>/FixPt
Constant */
	this.urlHashMap["SensAdapt:33:2:3:2"] = "SensAdapt.c:56";
	/* <S4>/FixPt
Data Type
Duplicate */
	this.urlHashMap["SensAdapt:33:2:3:3"] = "msg=rtwMsg_reducedBlock&block=SensAdapt/Repeating%20Sequence%20Stair1/LimitedCounter/Increment%20Real%20World/FixPt%20Data%20Type%20Duplicate";
	/* <S4>/FixPt
Sum1 */
	this.urlHashMap["SensAdapt:33:2:3:4"] = "SensAdapt.c:55";
	/* <S5>/Constant */
	this.urlHashMap["SensAdapt:33:2:5:4"] = "SensAdapt.c:62";
	/* <S5>/FixPt
Data Type
Duplicate1 */
	this.urlHashMap["SensAdapt:33:2:5:2"] = "msg=rtwMsg_reducedBlock&block=SensAdapt/Repeating%20Sequence%20Stair1/LimitedCounter/Wrap%20To%20Zero/FixPt%20Data%20Type%20Duplicate1";
	/* <S5>/FixPt
Switch */
	this.urlHashMap["SensAdapt:33:2:5:3"] = "SensAdapt.c:61,68";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
	RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
