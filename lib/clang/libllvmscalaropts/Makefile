# $FreeBSD$

.include <bsd.own.mk>

LIB=	llvmscalaropts

SRCDIR=	lib/Transforms/Scalar
SRCS=	ADCE.cpp \
	BasicBlockPlacement.cpp \
	CodeGenPrepare.cpp \
	ConstantProp.cpp \
	CorrelatedValuePropagation.cpp \
	DCE.cpp \
	DeadStoreElimination.cpp \
	EarlyCSE.cpp \
	GVN.cpp \
	IndVarSimplify.cpp \
	JumpThreading.cpp \
	LICM.cpp \
	LoopDeletion.cpp \
	LoopIdiomRecognize.cpp \
	LoopRotation.cpp \
	LoopStrengthReduce.cpp \
	LoopUnrollPass.cpp \
	LoopUnswitch.cpp \
	MemCpyOptimizer.cpp \
	ObjCARC.cpp \
	Reassociate.cpp \
	SCCP.cpp \
	ScalarReplAggregates.cpp \
	SimplifyCFGPass.cpp \
	SimplifyLibCalls.cpp \
	Sink.cpp \
	TailRecursionElimination.cpp

.if ${MK_CLANG_EXTRAS} != "no"
SRCS+=	LoopInstSimplify.cpp \
	LowerAtomic.cpp \
	Reg2Mem.cpp \
	Scalar.cpp
.endif

TGHDRS=	Intrinsics

.include "../clang.lib.mk"
