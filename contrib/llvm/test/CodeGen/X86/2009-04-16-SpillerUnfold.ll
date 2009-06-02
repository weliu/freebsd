; RUN: llvm-as < %s | llc -mtriple=x86_64-apple-darwin10.0 -relocation-model=pic -disable-fp-elim -stats |& grep {Number of modref unfolded}
; XFAIL: *
; 69408 removed the opportunity for this optimization to work

	%struct.SHA512_CTX = type { [8 x i64], i64, i64, %struct.anon, i32, i32 }
	%struct.anon = type { [16 x i64] }
@K512 = external constant [80 x i64], align 32		; <[80 x i64]*> [#uses=2]

define fastcc void @sha512_block_data_order(%struct.SHA512_CTX* nocapture %ctx, i8* nocapture %in, i64 %num) nounwind ssp {
entry:
	br label %bb349

bb349:		; preds = %bb349, %entry
	%e.0489 = phi i64 [ 0, %entry ], [ %e.0, %bb349 ]		; <i64> [#uses=3]
	%b.0472 = phi i64 [ 0, %entry ], [ %87, %bb349 ]		; <i64> [#uses=2]
	%asmtmp356 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 41, i64 %e.0489) nounwind		; <i64> [#uses=1]
	%0 = xor i64 0, %asmtmp356		; <i64> [#uses=1]
	%1 = add i64 0, %0		; <i64> [#uses=1]
	%2 = add i64 %1, 0		; <i64> [#uses=1]
	%3 = add i64 %2, 0		; <i64> [#uses=1]
	%4 = add i64 %3, 0		; <i64> [#uses=5]
	%asmtmp372 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 34, i64 %4) nounwind		; <i64> [#uses=1]
	%asmtmp373 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 39, i64 %4) nounwind		; <i64> [#uses=0]
	%5 = xor i64 %asmtmp372, 0		; <i64> [#uses=0]
	%6 = xor i64 0, %b.0472		; <i64> [#uses=1]
	%7 = and i64 %4, %6		; <i64> [#uses=1]
	%8 = xor i64 %7, 0		; <i64> [#uses=1]
	%9 = add i64 0, %8		; <i64> [#uses=1]
	%10 = add i64 %9, 0		; <i64> [#uses=2]
	%asmtmp377 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 61, i64 0) nounwind		; <i64> [#uses=1]
	%11 = xor i64 0, %asmtmp377		; <i64> [#uses=1]
	%12 = add i64 0, %11		; <i64> [#uses=1]
	%13 = add i64 %12, 0		; <i64> [#uses=1]
	%not381 = xor i64 0, -1		; <i64> [#uses=1]
	%14 = and i64 %e.0489, %not381		; <i64> [#uses=1]
	%15 = xor i64 0, %14		; <i64> [#uses=1]
	%16 = add i64 %15, 0		; <i64> [#uses=1]
	%17 = add i64 %16, %13		; <i64> [#uses=1]
	%18 = add i64 %17, 0		; <i64> [#uses=1]
	%19 = add i64 %18, 0		; <i64> [#uses=2]
	%20 = add i64 %19, %b.0472		; <i64> [#uses=3]
	%21 = add i64 %19, 0		; <i64> [#uses=1]
	%22 = add i64 %21, 0		; <i64> [#uses=1]
	%23 = add i32 0, 12		; <i32> [#uses=1]
	%24 = and i32 %23, 12		; <i32> [#uses=1]
	%25 = zext i32 %24 to i64		; <i64> [#uses=1]
	%26 = getelementptr [16 x i64]* null, i64 0, i64 %25		; <i64*> [#uses=0]
	%27 = add i64 0, %e.0489		; <i64> [#uses=1]
	%28 = add i64 %27, 0		; <i64> [#uses=1]
	%29 = add i64 %28, 0		; <i64> [#uses=1]
	%30 = add i64 %29, 0		; <i64> [#uses=2]
	%31 = and i64 %10, %4		; <i64> [#uses=1]
	%32 = xor i64 0, %31		; <i64> [#uses=1]
	%33 = add i64 %30, 0		; <i64> [#uses=3]
	%34 = add i64 %30, %32		; <i64> [#uses=1]
	%35 = add i64 %34, 0		; <i64> [#uses=1]
	%36 = and i64 %33, %20		; <i64> [#uses=1]
	%37 = xor i64 %36, 0		; <i64> [#uses=1]
	%38 = add i64 %37, 0		; <i64> [#uses=1]
	%39 = add i64 %38, 0		; <i64> [#uses=1]
	%40 = add i64 %39, 0		; <i64> [#uses=1]
	%41 = add i64 %40, 0		; <i64> [#uses=1]
	%42 = add i64 %41, %4		; <i64> [#uses=3]
	%43 = or i32 0, 6		; <i32> [#uses=1]
	%44 = and i32 %43, 14		; <i32> [#uses=1]
	%45 = zext i32 %44 to i64		; <i64> [#uses=1]
	%46 = getelementptr [16 x i64]* null, i64 0, i64 %45		; <i64*> [#uses=1]
	%not417 = xor i64 %42, -1		; <i64> [#uses=1]
	%47 = and i64 %20, %not417		; <i64> [#uses=1]
	%48 = xor i64 0, %47		; <i64> [#uses=1]
	%49 = getelementptr [80 x i64]* @K512, i64 0, i64 0		; <i64*> [#uses=1]
	%50 = load i64* %49, align 8		; <i64> [#uses=1]
	%51 = add i64 %48, 0		; <i64> [#uses=1]
	%52 = add i64 %51, 0		; <i64> [#uses=1]
	%53 = add i64 %52, 0		; <i64> [#uses=1]
	%54 = add i64 %53, %50		; <i64> [#uses=2]
	%asmtmp420 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 34, i64 0) nounwind		; <i64> [#uses=1]
	%asmtmp421 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 39, i64 0) nounwind		; <i64> [#uses=1]
	%55 = xor i64 %asmtmp420, 0		; <i64> [#uses=1]
	%56 = xor i64 %55, %asmtmp421		; <i64> [#uses=1]
	%57 = add i64 %54, %10		; <i64> [#uses=5]
	%58 = add i64 %54, 0		; <i64> [#uses=1]
	%59 = add i64 %58, %56		; <i64> [#uses=2]
	%60 = or i32 0, 7		; <i32> [#uses=1]
	%61 = and i32 %60, 15		; <i32> [#uses=1]
	%62 = zext i32 %61 to i64		; <i64> [#uses=1]
	%63 = getelementptr [16 x i64]* null, i64 0, i64 %62		; <i64*> [#uses=2]
	%64 = load i64* null, align 8		; <i64> [#uses=1]
	%65 = lshr i64 %64, 6		; <i64> [#uses=1]
	%66 = xor i64 0, %65		; <i64> [#uses=1]
	%67 = xor i64 %66, 0		; <i64> [#uses=1]
	%68 = load i64* %46, align 8		; <i64> [#uses=1]
	%69 = load i64* null, align 8		; <i64> [#uses=1]
	%70 = add i64 %68, 0		; <i64> [#uses=1]
	%71 = add i64 %70, %67		; <i64> [#uses=1]
	%72 = add i64 %71, %69		; <i64> [#uses=1]
	%asmtmp427 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 18, i64 %57) nounwind		; <i64> [#uses=1]
	%asmtmp428 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 41, i64 %57) nounwind		; <i64> [#uses=1]
	%73 = xor i64 %asmtmp427, 0		; <i64> [#uses=1]
	%74 = xor i64 %73, %asmtmp428		; <i64> [#uses=1]
	%75 = and i64 %57, %42		; <i64> [#uses=1]
	%not429 = xor i64 %57, -1		; <i64> [#uses=1]
	%76 = and i64 %33, %not429		; <i64> [#uses=1]
	%77 = xor i64 %75, %76		; <i64> [#uses=1]
	%78 = getelementptr [80 x i64]* @K512, i64 0, i64 0		; <i64*> [#uses=1]
	%79 = load i64* %78, align 16		; <i64> [#uses=1]
	%80 = add i64 %77, %20		; <i64> [#uses=1]
	%81 = add i64 %80, %72		; <i64> [#uses=1]
	%82 = add i64 %81, %74		; <i64> [#uses=1]
	%83 = add i64 %82, %79		; <i64> [#uses=1]
	%asmtmp432 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 34, i64 %59) nounwind		; <i64> [#uses=1]
	%asmtmp433 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 39, i64 %59) nounwind		; <i64> [#uses=1]
	%84 = xor i64 %asmtmp432, 0		; <i64> [#uses=1]
	%85 = xor i64 %84, %asmtmp433		; <i64> [#uses=1]
	%86 = add i64 %83, %22		; <i64> [#uses=2]
	%87 = add i64 0, %85		; <i64> [#uses=1]
	%asmtmp435 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 8, i64 0) nounwind		; <i64> [#uses=1]
	%88 = xor i64 0, %asmtmp435		; <i64> [#uses=1]
	%89 = load i64* null, align 8		; <i64> [#uses=3]
	%asmtmp436 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 19, i64 %89) nounwind		; <i64> [#uses=1]
	%asmtmp437 = call i64 asm "rorq $1,$0", "=r,J,0,~{dirflag},~{fpsr},~{flags},~{cc}"(i32 61, i64 %89) nounwind		; <i64> [#uses=1]
	%90 = lshr i64 %89, 6		; <i64> [#uses=1]
	%91 = xor i64 %asmtmp436, %90		; <i64> [#uses=1]
	%92 = xor i64 %91, %asmtmp437		; <i64> [#uses=1]
	%93 = load i64* %63, align 8		; <i64> [#uses=1]
	%94 = load i64* null, align 8		; <i64> [#uses=1]
	%95 = add i64 %93, %88		; <i64> [#uses=1]
	%96 = add i64 %95, %92		; <i64> [#uses=1]
	%97 = add i64 %96, %94		; <i64> [#uses=2]
	store i64 %97, i64* %63, align 8
	%98 = and i64 %86, %57		; <i64> [#uses=1]
	%not441 = xor i64 %86, -1		; <i64> [#uses=1]
	%99 = and i64 %42, %not441		; <i64> [#uses=1]
	%100 = xor i64 %98, %99		; <i64> [#uses=1]
	%101 = add i64 %100, %33		; <i64> [#uses=1]
	%102 = add i64 %101, %97		; <i64> [#uses=1]
	%103 = add i64 %102, 0		; <i64> [#uses=1]
	%104 = add i64 %103, 0		; <i64> [#uses=1]
	%e.0 = add i64 %104, %35		; <i64> [#uses=1]
	br label %bb349
}
