
a.out:     file format elf32-i386


Disassembly of section .interp:

08048134 <.interp>:
 8048134:	2f                   	das    
 8048135:	6c                   	insb   (%dx),%es:(%edi)
 8048136:	69 62 2f 6c 64 2d 6c 	imul   $0x6c2d646c,0x2f(%edx),%esp
 804813d:	69 6e 75 78 2e 73 6f 	imul   $0x6f732e78,0x75(%esi),%ebp
 8048144:	2e 32 00             	xor    %cs:(%eax),%al

Disassembly of section .note.ABI-tag:

08048148 <.note.ABI-tag>:
 8048148:	04 00                	add    $0x0,%al
 804814a:	00 00                	add    %al,(%eax)
 804814c:	10 00                	adc    %al,(%eax)
 804814e:	00 00                	add    %al,(%eax)
 8048150:	01 00                	add    %eax,(%eax)
 8048152:	00 00                	add    %al,(%eax)
 8048154:	47                   	inc    %edi
 8048155:	4e                   	dec    %esi
 8048156:	55                   	push   %ebp
 8048157:	00 00                	add    %al,(%eax)
 8048159:	00 00                	add    %al,(%eax)
 804815b:	00 02                	add    %al,(%edx)
 804815d:	00 00                	add    %al,(%eax)
 804815f:	00 06                	add    %al,(%esi)
 8048161:	00 00                	add    %al,(%eax)
 8048163:	00 1a                	add    %bl,(%edx)
 8048165:	00 00                	add    %al,(%eax)
	...

Disassembly of section .note.gnu.build-id:

08048168 <.note.gnu.build-id>:
 8048168:	04 00                	add    $0x0,%al
 804816a:	00 00                	add    %al,(%eax)
 804816c:	14 00                	adc    $0x0,%al
 804816e:	00 00                	add    %al,(%eax)
 8048170:	03 00                	add    (%eax),%eax
 8048172:	00 00                	add    %al,(%eax)
 8048174:	47                   	inc    %edi
 8048175:	4e                   	dec    %esi
 8048176:	55                   	push   %ebp
 8048177:	00 7a 97             	add    %bh,-0x69(%edx)
 804817a:	ac                   	lods   %ds:(%esi),%al
 804817b:	b4 ea                	mov    $0xea,%ah
 804817d:	41                   	inc    %ecx
 804817e:	53                   	push   %ebx
 804817f:	64                   	fs
 8048180:	4a                   	dec    %edx
 8048181:	d0 d0                	rcl    %al
 8048183:	5a                   	pop    %edx
 8048184:	e1 5a                	loope  80481e0 <_init-0x18c>
 8048186:	29                   	.byte 0x29
 8048187:	84 0e                	test   %cl,(%esi)
 8048189:	99                   	cltd   
 804818a:	6c                   	insb   (%dx),%es:(%edi)
 804818b:	6c                   	insb   (%dx),%es:(%edi)

Disassembly of section .hash:

0804818c <.hash>:
 804818c:	03 00                	add    (%eax),%eax
 804818e:	00 00                	add    %al,(%eax)
 8048190:	0a 00                	or     (%eax),%al
 8048192:	00 00                	add    %al,(%eax)
 8048194:	05 00 00 00 07       	add    $0x7000000,%eax
 8048199:	00 00                	add    %al,(%eax)
 804819b:	00 08                	add    %cl,(%eax)
	...
 80481a5:	00 00                	add    %al,(%eax)
 80481a7:	00 01                	add    %al,(%ecx)
	...
 80481b1:	00 00                	add    %al,(%eax)
 80481b3:	00 03                	add    %al,(%ebx)
 80481b5:	00 00                	add    %al,(%eax)
 80481b7:	00 04 00             	add    %al,(%eax,%eax,1)
 80481ba:	00 00                	add    %al,(%eax)
 80481bc:	06                   	push   %es
 80481bd:	00 00                	add    %al,(%eax)
 80481bf:	00 09                	add    %cl,(%ecx)
 80481c1:	00 00                	add    %al,(%eax)
 80481c3:	00 02                	add    %al,(%edx)
 80481c5:	00 00                	add    %al,(%eax)
	...

Disassembly of section .gnu.hash:

080481c8 <.gnu.hash>:
 80481c8:	02 00                	add    (%eax),%al
 80481ca:	00 00                	add    %al,(%eax)
 80481cc:	09 00                	or     %eax,(%eax)
 80481ce:	00 00                	add    %al,(%eax)
 80481d0:	01 00                	add    %eax,(%eax)
 80481d2:	00 00                	add    %al,(%eax)
 80481d4:	05 00 00 00 00       	add    $0x0,%eax
 80481d9:	20 00                	and    %al,(%eax)
 80481db:	20 00                	and    %al,(%eax)
 80481dd:	00 00                	add    %al,(%eax)
 80481df:	00 09                	add    %cl,(%ecx)
 80481e1:	00 00                	add    %al,(%eax)
 80481e3:	00                   	.byte 0x0
 80481e4:	ad                   	lods   %ds:(%esi),%eax
 80481e5:	4b                   	dec    %ebx
 80481e6:	e3 c0                	jecxz  80481a8 <_init-0x1c4>

Disassembly of section .dynsym:

080481e8 <.dynsym>:
	...
 80481f8:	3f                   	aas    
	...
 8048201:	00 00                	add    %al,(%eax)
 8048203:	00 12                	add    %dl,(%edx)
 8048205:	00 00                	add    %al,(%eax)
 8048207:	00 2e                	add    %ch,(%esi)
	...
 8048211:	00 00                	add    %al,(%eax)
 8048213:	00 12                	add    %dl,(%edx)
 8048215:	00 00                	add    %al,(%eax)
 8048217:	00 46 00             	add    %al,0x0(%esi)
	...
 8048222:	00 00                	add    %al,(%eax)
 8048224:	12 00                	adc    (%eax),%al
 8048226:	00 00                	add    %al,(%eax)
 8048228:	35 00 00 00 00       	xor    $0x0,%eax
 804822d:	00 00                	add    %al,(%eax)
 804822f:	00 00                	add    %al,(%eax)
 8048231:	00 00                	add    %al,(%eax)
 8048233:	00 12                	add    %dl,(%edx)
 8048235:	00 00                	add    %al,(%eax)
 8048237:	00 01                	add    %al,(%ecx)
	...
 8048241:	00 00                	add    %al,(%eax)
 8048243:	00 20                	add    %ah,(%eax)
 8048245:	00 00                	add    %al,(%eax)
 8048247:	00 29                	add    %ch,(%ecx)
	...
 8048251:	00 00                	add    %al,(%eax)
 8048253:	00 12                	add    %dl,(%edx)
 8048255:	00 00                	add    %al,(%eax)
 8048257:	00 4c 00 00          	add    %cl,0x0(%eax,%eax,1)
	...
 8048263:	00 12                	add    %dl,(%edx)
 8048265:	00 00                	add    %al,(%eax)
 8048267:	00 3a                	add    %bh,(%edx)
	...
 8048271:	00 00                	add    %al,(%eax)
 8048273:	00 12                	add    %dl,(%edx)
 8048275:	00 00                	add    %al,(%eax)
 8048277:	00 1a                	add    %bl,(%edx)
 8048279:	00 00                	add    %al,(%eax)
 804827b:	00 7c 86 04          	add    %bh,0x4(%esi,%eax,4)
 804827f:	08 04 00             	or     %al,(%eax,%eax,1)
 8048282:	00 00                	add    %al,(%eax)
 8048284:	11 00                	adc    %eax,(%eax)
 8048286:	10 00                	adc    %al,(%eax)

Disassembly of section .dynstr:

08048288 <.dynstr>:
 8048288:	00 5f 5f             	add    %bl,0x5f(%edi)
 804828b:	67 6d                	insl   (%dx),%es:(%di)
 804828d:	6f                   	outsl  %ds:(%esi),(%dx)
 804828e:	6e                   	outsb  %ds:(%esi),(%dx)
 804828f:	5f                   	pop    %edi
 8048290:	73 74                	jae    8048306 <_init-0x66>
 8048292:	61                   	popa   
 8048293:	72 74                	jb     8048309 <_init-0x63>
 8048295:	5f                   	pop    %edi
 8048296:	5f                   	pop    %edi
 8048297:	00 6c 69 62          	add    %ch,0x62(%ecx,%ebp,2)
 804829b:	63 2e                	arpl   %bp,(%esi)
 804829d:	73 6f                	jae    804830e <_init-0x5e>
 804829f:	2e 36 00 5f 49       	cs add %bl,%cs:%ss:0x49(%edi)
 80482a4:	4f                   	dec    %edi
 80482a5:	5f                   	pop    %edi
 80482a6:	73 74                	jae    804831c <_init-0x50>
 80482a8:	64 69 6e 5f 75 73 65 	imul   $0x64657375,%fs:0x5f(%esi),%ebp
 80482af:	64 
 80482b0:	00 65 78             	add    %ah,0x78(%ebp)
 80482b3:	69 74 00 73 69 67 6e 	imul   $0x616e6769,0x73(%eax,%eax,1),%esi
 80482ba:	61 
 80482bb:	6c                   	insb   (%dx),%es:(%edi)
 80482bc:	00 70 75             	add    %dh,0x75(%eax)
 80482bf:	74 73                	je     8048334 <_init-0x38>
 80482c1:	00 66 6f             	add    %ah,0x6f(%esi)
 80482c4:	72 6b                	jb     8048331 <_init-0x3b>
 80482c6:	00 70 72             	add    %dh,0x72(%eax)
 80482c9:	69 6e 74 66 00 73 6c 	imul   $0x6c730066,0x74(%esi),%ebp
 80482d0:	65                   	gs
 80482d1:	65                   	gs
 80482d2:	70 00                	jo     80482d4 <_init-0x98>
 80482d4:	5f                   	pop    %edi
 80482d5:	5f                   	pop    %edi
 80482d6:	6c                   	insb   (%dx),%es:(%edi)
 80482d7:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%edx),%esp
 80482de:	72 74                	jb     8048354 <_init-0x18>
 80482e0:	5f                   	pop    %edi
 80482e1:	6d                   	insl   (%dx),%es:(%edi)
 80482e2:	61                   	popa   
 80482e3:	69 6e 00 47 4c 49 42 	imul   $0x42494c47,0x0(%esi),%ebp
 80482ea:	43                   	inc    %ebx
 80482eb:	5f                   	pop    %edi
 80482ec:	32 2e                	xor    (%esi),%ch
 80482ee:	30 00                	xor    %al,(%eax)

Disassembly of section .gnu.version:

080482f0 <.gnu.version>:
 80482f0:	00 00                	add    %al,(%eax)
 80482f2:	02 00                	add    (%eax),%al
 80482f4:	02 00                	add    (%eax),%al
 80482f6:	02 00                	add    (%eax),%al
 80482f8:	02 00                	add    (%eax),%al
 80482fa:	00 00                	add    %al,(%eax)
 80482fc:	02 00                	add    (%eax),%al
 80482fe:	02 00                	add    (%eax),%al
 8048300:	02 00                	add    (%eax),%al
 8048302:	01 00                	add    %eax,(%eax)

Disassembly of section .gnu.version_r:

08048304 <.gnu.version_r>:
 8048304:	01 00                	add    %eax,(%eax)
 8048306:	01 00                	add    %eax,(%eax)
 8048308:	10 00                	adc    %al,(%eax)
 804830a:	00 00                	add    %al,(%eax)
 804830c:	10 00                	adc    %al,(%eax)
 804830e:	00 00                	add    %al,(%eax)
 8048310:	00 00                	add    %al,(%eax)
 8048312:	00 00                	add    %al,(%eax)
 8048314:	10 69 69             	adc    %ch,0x69(%ecx)
 8048317:	0d 00 00 02 00       	or     $0x20000,%eax
 804831c:	5e                   	pop    %esi
 804831d:	00 00                	add    %al,(%eax)
 804831f:	00 00                	add    %al,(%eax)
 8048321:	00 00                	add    %al,(%eax)
	...

Disassembly of section .rel.dyn:

08048324 <.rel.dyn>:
 8048324:	ac                   	lods   %ds:(%esi),%al
 8048325:	98                   	cwtl   
 8048326:	04 08                	add    $0x8,%al
 8048328:	06                   	push   %es
 8048329:	05                   	.byte 0x5
	...

Disassembly of section .rel.plt:

0804832c <.rel.plt>:
 804832c:	bc 98 04 08 07       	mov    $0x7080498,%esp
 8048331:	01 00                	add    %eax,(%eax)
 8048333:	00 c0                	add    %al,%al
 8048335:	98                   	cwtl   
 8048336:	04 08                	add    $0x8,%al
 8048338:	07                   	pop    %es
 8048339:	02 00                	add    (%eax),%al
 804833b:	00 c4                	add    %al,%ah
 804833d:	98                   	cwtl   
 804833e:	04 08                	add    $0x8,%al
 8048340:	07                   	pop    %es
 8048341:	03 00                	add    (%eax),%eax
 8048343:	00 c8                	add    %cl,%al
 8048345:	98                   	cwtl   
 8048346:	04 08                	add    $0x8,%al
 8048348:	07                   	pop    %es
 8048349:	04 00                	add    $0x0,%al
 804834b:	00 cc                	add    %cl,%ah
 804834d:	98                   	cwtl   
 804834e:	04 08                	add    $0x8,%al
 8048350:	07                   	pop    %es
 8048351:	05 00 00 d0 98       	add    $0x98d00000,%eax
 8048356:	04 08                	add    $0x8,%al
 8048358:	07                   	pop    %es
 8048359:	06                   	push   %es
 804835a:	00 00                	add    %al,(%eax)
 804835c:	d4 98                	aam    $0x98
 804835e:	04 08                	add    $0x8,%al
 8048360:	07                   	pop    %es
 8048361:	07                   	pop    %es
 8048362:	00 00                	add    %al,(%eax)
 8048364:	d8 98 04 08 07 08    	fcomps 0x8070804(%eax)
	...

Disassembly of section .init:

0804836c <_init>:
 804836c:	55                   	push   %ebp
 804836d:	89 e5                	mov    %esp,%ebp
 804836f:	53                   	push   %ebx
 8048370:	83 ec 04             	sub    $0x4,%esp
 8048373:	e8 00 00 00 00       	call   8048378 <_init+0xc>
 8048378:	5b                   	pop    %ebx
 8048379:	81 c3 38 15 00 00    	add    $0x1538,%ebx
 804837f:	8b 93 fc ff ff ff    	mov    -0x4(%ebx),%edx
 8048385:	85 d2                	test   %edx,%edx
 8048387:	74 05                	je     804838e <_init+0x22>
 8048389:	e8 62 00 00 00       	call   80483f0 <__gmon_start__@plt>
 804838e:	58                   	pop    %eax
 804838f:	5b                   	pop    %ebx
 8048390:	c9                   	leave  
 8048391:	c3                   	ret    

Disassembly of section .plt:

080483a0 <printf@plt-0x10>:
 80483a0:	ff 35 b4 98 04 08    	pushl  0x80498b4
 80483a6:	ff 25 b8 98 04 08    	jmp    *0x80498b8
 80483ac:	00 00                	add    %al,(%eax)
	...

080483b0 <printf@plt>:
 80483b0:	ff 25 bc 98 04 08    	jmp    *0x80498bc
 80483b6:	68 00 00 00 00       	push   $0x0
 80483bb:	e9 e0 ff ff ff       	jmp    80483a0 <_init+0x34>

080483c0 <signal@plt>:
 80483c0:	ff 25 c0 98 04 08    	jmp    *0x80498c0
 80483c6:	68 08 00 00 00       	push   $0x8
 80483cb:	e9 d0 ff ff ff       	jmp    80483a0 <_init+0x34>

080483d0 <sleep@plt>:
 80483d0:	ff 25 c4 98 04 08    	jmp    *0x80498c4
 80483d6:	68 10 00 00 00       	push   $0x10
 80483db:	e9 c0 ff ff ff       	jmp    80483a0 <_init+0x34>

080483e0 <puts@plt>:
 80483e0:	ff 25 c8 98 04 08    	jmp    *0x80498c8
 80483e6:	68 18 00 00 00       	push   $0x18
 80483eb:	e9 b0 ff ff ff       	jmp    80483a0 <_init+0x34>

080483f0 <__gmon_start__@plt>:
 80483f0:	ff 25 cc 98 04 08    	jmp    *0x80498cc
 80483f6:	68 20 00 00 00       	push   $0x20
 80483fb:	e9 a0 ff ff ff       	jmp    80483a0 <_init+0x34>

08048400 <exit@plt>:
 8048400:	ff 25 d0 98 04 08    	jmp    *0x80498d0
 8048406:	68 28 00 00 00       	push   $0x28
 804840b:	e9 90 ff ff ff       	jmp    80483a0 <_init+0x34>

08048410 <__libc_start_main@plt>:
 8048410:	ff 25 d4 98 04 08    	jmp    *0x80498d4
 8048416:	68 30 00 00 00       	push   $0x30
 804841b:	e9 80 ff ff ff       	jmp    80483a0 <_init+0x34>

08048420 <fork@plt>:
 8048420:	ff 25 d8 98 04 08    	jmp    *0x80498d8
 8048426:	68 38 00 00 00       	push   $0x38
 804842b:	e9 70 ff ff ff       	jmp    80483a0 <_init+0x34>

Disassembly of section .text:

08048430 <_start>:
 8048430:	31 ed                	xor    %ebp,%ebp
 8048432:	5e                   	pop    %esi
 8048433:	89 e1                	mov    %esp,%ecx
 8048435:	83 e4 f0             	and    $0xfffffff0,%esp
 8048438:	50                   	push   %eax
 8048439:	54                   	push   %esp
 804843a:	52                   	push   %edx
 804843b:	68 f0 85 04 08       	push   $0x80485f0
 8048440:	68 00 86 04 08       	push   $0x8048600
 8048445:	51                   	push   %ecx
 8048446:	56                   	push   %esi
 8048447:	68 4c 85 04 08       	push   $0x804854c
 804844c:	e8 bf ff ff ff       	call   8048410 <__libc_start_main@plt>
 8048451:	f4                   	hlt    
 8048452:	90                   	nop
 8048453:	90                   	nop
 8048454:	90                   	nop
 8048455:	90                   	nop
 8048456:	90                   	nop
 8048457:	90                   	nop
 8048458:	90                   	nop
 8048459:	90                   	nop
 804845a:	90                   	nop
 804845b:	90                   	nop
 804845c:	90                   	nop
 804845d:	90                   	nop
 804845e:	90                   	nop
 804845f:	90                   	nop

08048460 <deregister_tm_clones>:
 8048460:	b8 e7 98 04 08       	mov    $0x80498e7,%eax
 8048465:	2d e4 98 04 08       	sub    $0x80498e4,%eax
 804846a:	83 f8 06             	cmp    $0x6,%eax
 804846d:	77 02                	ja     8048471 <deregister_tm_clones+0x11>
 804846f:	f3 c3                	repz ret 
 8048471:	b8 00 00 00 00       	mov    $0x0,%eax
 8048476:	85 c0                	test   %eax,%eax
 8048478:	74 f5                	je     804846f <deregister_tm_clones+0xf>
 804847a:	55                   	push   %ebp
 804847b:	89 e5                	mov    %esp,%ebp
 804847d:	83 ec 18             	sub    $0x18,%esp
 8048480:	c7 04 24 e4 98 04 08 	movl   $0x80498e4,(%esp)
 8048487:	ff d0                	call   *%eax
 8048489:	c9                   	leave  
 804848a:	c3                   	ret    
 804848b:	90                   	nop
 804848c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

08048490 <register_tm_clones>:
 8048490:	b8 e4 98 04 08       	mov    $0x80498e4,%eax
 8048495:	2d e4 98 04 08       	sub    $0x80498e4,%eax
 804849a:	c1 f8 02             	sar    $0x2,%eax
 804849d:	89 c2                	mov    %eax,%edx
 804849f:	c1 ea 1f             	shr    $0x1f,%edx
 80484a2:	01 d0                	add    %edx,%eax
 80484a4:	d1 f8                	sar    %eax
 80484a6:	75 02                	jne    80484aa <register_tm_clones+0x1a>
 80484a8:	f3 c3                	repz ret 
 80484aa:	ba 00 00 00 00       	mov    $0x0,%edx
 80484af:	85 d2                	test   %edx,%edx
 80484b1:	74 f5                	je     80484a8 <register_tm_clones+0x18>
 80484b3:	55                   	push   %ebp
 80484b4:	89 e5                	mov    %esp,%ebp
 80484b6:	83 ec 18             	sub    $0x18,%esp
 80484b9:	89 44 24 04          	mov    %eax,0x4(%esp)
 80484bd:	c7 04 24 e4 98 04 08 	movl   $0x80498e4,(%esp)
 80484c4:	ff d2                	call   *%edx
 80484c6:	c9                   	leave  
 80484c7:	c3                   	ret    
 80484c8:	90                   	nop
 80484c9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

080484d0 <__do_global_dtors_aux>:
 80484d0:	80 3d e4 98 04 08 00 	cmpb   $0x0,0x80498e4
 80484d7:	75 13                	jne    80484ec <__do_global_dtors_aux+0x1c>
 80484d9:	55                   	push   %ebp
 80484da:	89 e5                	mov    %esp,%ebp
 80484dc:	83 ec 08             	sub    $0x8,%esp
 80484df:	e8 7c ff ff ff       	call   8048460 <deregister_tm_clones>
 80484e4:	c6 05 e4 98 04 08 01 	movb   $0x1,0x80498e4
 80484eb:	c9                   	leave  
 80484ec:	f3 c3                	repz ret 
 80484ee:	66 90                	xchg   %ax,%ax

080484f0 <frame_dummy>:
 80484f0:	a1 b8 97 04 08       	mov    0x80497b8,%eax
 80484f5:	85 c0                	test   %eax,%eax
 80484f7:	74 1e                	je     8048517 <frame_dummy+0x27>
 80484f9:	b8 00 00 00 00       	mov    $0x0,%eax
 80484fe:	85 c0                	test   %eax,%eax
 8048500:	74 15                	je     8048517 <frame_dummy+0x27>
 8048502:	55                   	push   %ebp
 8048503:	89 e5                	mov    %esp,%ebp
 8048505:	83 ec 18             	sub    $0x18,%esp
 8048508:	c7 04 24 b8 97 04 08 	movl   $0x80497b8,(%esp)
 804850f:	ff d0                	call   *%eax
 8048511:	c9                   	leave  
 8048512:	e9 79 ff ff ff       	jmp    8048490 <register_tm_clones>
 8048517:	e9 74 ff ff ff       	jmp    8048490 <register_tm_clones>

0804851c <child_func>:
 804851c:	55                   	push   %ebp
 804851d:	89 e5                	mov    %esp,%ebp
 804851f:	83 ec 18             	sub    $0x18,%esp
 8048522:	83 7d 08 11          	cmpl   $0x11,0x8(%ebp)
 8048526:	75 0e                	jne    8048536 <child_func+0x1a>
 8048528:	c7 04 24 80 86 04 08 	movl   $0x8048680,(%esp)
 804852f:	e8 ac fe ff ff       	call   80483e0 <puts@plt>
 8048534:	eb 13                	jmp    8048549 <child_func+0x2d>
 8048536:	8b 45 08             	mov    0x8(%ebp),%eax
 8048539:	89 44 24 04          	mov    %eax,0x4(%esp)
 804853d:	c7 04 24 97 86 04 08 	movl   $0x8048697,(%esp)
 8048544:	e8 67 fe ff ff       	call   80483b0 <printf@plt>
 8048549:	90                   	nop
 804854a:	c9                   	leave  
 804854b:	c3                   	ret    

0804854c <main>:
 804854c:	55                   	push   %ebp
 804854d:	89 e5                	mov    %esp,%ebp
 804854f:	83 e4 f0             	and    $0xfffffff0,%esp
 8048552:	83 ec 20             	sub    $0x20,%esp
 8048555:	e8 c6 fe ff ff       	call   8048420 <fork@plt>
 804855a:	89 44 24 1c          	mov    %eax,0x1c(%esp)
 804855e:	83 7c 24 1c 00       	cmpl   $0x0,0x1c(%esp)
 8048563:	79 0c                	jns    8048571 <main+0x25>
 8048565:	c7 04 24 ac 86 04 08 	movl   $0x80486ac,(%esp)
 804856c:	e8 6f fe ff ff       	call   80483e0 <puts@plt>
 8048571:	83 7c 24 1c 00       	cmpl   $0x0,0x1c(%esp)
 8048576:	75 18                	jne    8048590 <main+0x44>
 8048578:	c7 04 24 b9 86 04 08 	movl   $0x80486b9,(%esp)
 804857f:	e8 5c fe ff ff       	call   80483e0 <puts@plt>
 8048584:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 804858b:	e8 70 fe ff ff       	call   8048400 <exit@plt>
 8048590:	83 7c 24 1c 00       	cmpl   $0x0,0x1c(%esp)
 8048595:	7e 4b                	jle    80485e2 <main+0x96>
 8048597:	c7 04 24 cc 86 04 08 	movl   $0x80486cc,(%esp)
 804859e:	e8 3d fe ff ff       	call   80483e0 <puts@plt>
 80485a3:	c7 44 24 04 1c 85 04 	movl   $0x804851c,0x4(%esp)
 80485aa:	08 
 80485ab:	c7 04 24 11 00 00 00 	movl   $0x11,(%esp)
 80485b2:	e8 09 fe ff ff       	call   80483c0 <signal@plt>
 80485b7:	83 f8 ff             	cmp    $0xffffffff,%eax
 80485ba:	75 0e                	jne    80485ca <main+0x7e>
 80485bc:	c7 04 24 e0 86 04 08 	movl   $0x80486e0,(%esp)
 80485c3:	e8 18 fe ff ff       	call   80483e0 <puts@plt>
 80485c8:	eb 0c                	jmp    80485d6 <main+0x8a>
 80485ca:	c7 04 24 f0 86 04 08 	movl   $0x80486f0,(%esp)
 80485d1:	e8 0a fe ff ff       	call   80483e0 <puts@plt>
 80485d6:	c7 04 24 05 00 00 00 	movl   $0x5,(%esp)
 80485dd:	e8 ee fd ff ff       	call   80483d0 <sleep@plt>
 80485e2:	b8 00 00 00 00       	mov    $0x0,%eax
 80485e7:	c9                   	leave  
 80485e8:	c3                   	ret    
 80485e9:	90                   	nop
 80485ea:	90                   	nop
 80485eb:	90                   	nop
 80485ec:	90                   	nop
 80485ed:	90                   	nop
 80485ee:	90                   	nop
 80485ef:	90                   	nop

080485f0 <__libc_csu_fini>:
 80485f0:	55                   	push   %ebp
 80485f1:	89 e5                	mov    %esp,%ebp
 80485f3:	5d                   	pop    %ebp
 80485f4:	c3                   	ret    
 80485f5:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 80485f9:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048600 <__libc_csu_init>:
 8048600:	55                   	push   %ebp
 8048601:	89 e5                	mov    %esp,%ebp
 8048603:	57                   	push   %edi
 8048604:	56                   	push   %esi
 8048605:	53                   	push   %ebx
 8048606:	e8 4f 00 00 00       	call   804865a <__i686.get_pc_thunk.bx>
 804860b:	81 c3 a5 12 00 00    	add    $0x12a5,%ebx
 8048611:	83 ec 1c             	sub    $0x1c,%esp
 8048614:	e8 53 fd ff ff       	call   804836c <_init>
 8048619:	8d bb 04 ff ff ff    	lea    -0xfc(%ebx),%edi
 804861f:	8d 83 00 ff ff ff    	lea    -0x100(%ebx),%eax
 8048625:	29 c7                	sub    %eax,%edi
 8048627:	c1 ff 02             	sar    $0x2,%edi
 804862a:	85 ff                	test   %edi,%edi
 804862c:	74 24                	je     8048652 <__libc_csu_init+0x52>
 804862e:	31 f6                	xor    %esi,%esi
 8048630:	8b 45 10             	mov    0x10(%ebp),%eax
 8048633:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048637:	8b 45 0c             	mov    0xc(%ebp),%eax
 804863a:	89 44 24 04          	mov    %eax,0x4(%esp)
 804863e:	8b 45 08             	mov    0x8(%ebp),%eax
 8048641:	89 04 24             	mov    %eax,(%esp)
 8048644:	ff 94 b3 00 ff ff ff 	call   *-0x100(%ebx,%esi,4)
 804864b:	83 c6 01             	add    $0x1,%esi
 804864e:	39 fe                	cmp    %edi,%esi
 8048650:	72 de                	jb     8048630 <__libc_csu_init+0x30>
 8048652:	83 c4 1c             	add    $0x1c,%esp
 8048655:	5b                   	pop    %ebx
 8048656:	5e                   	pop    %esi
 8048657:	5f                   	pop    %edi
 8048658:	5d                   	pop    %ebp
 8048659:	c3                   	ret    

0804865a <__i686.get_pc_thunk.bx>:
 804865a:	8b 1c 24             	mov    (%esp),%ebx
 804865d:	c3                   	ret    
 804865e:	90                   	nop
 804865f:	90                   	nop

Disassembly of section .fini:

08048660 <_fini>:
 8048660:	55                   	push   %ebp
 8048661:	89 e5                	mov    %esp,%ebp
 8048663:	53                   	push   %ebx
 8048664:	83 ec 04             	sub    $0x4,%esp
 8048667:	e8 00 00 00 00       	call   804866c <_fini+0xc>
 804866c:	5b                   	pop    %ebx
 804866d:	81 c3 44 12 00 00    	add    $0x1244,%ebx
 8048673:	59                   	pop    %ecx
 8048674:	5b                   	pop    %ebx
 8048675:	c9                   	leave  
 8048676:	c3                   	ret    

Disassembly of section .rodata:

08048678 <_fp_hw>:
 8048678:	03 00                	add    (%eax),%eax
	...

0804867c <_IO_stdin_used>:
 804867c:	01 00                	add    %eax,(%eax)
 804867e:	02 00                	add    (%eax),%al
 8048680:	67                   	addr16
 8048681:	65                   	gs
 8048682:	74 20                	je     80486a4 <_IO_stdin_used+0x28>
 8048684:	74 68                	je     80486ee <_IO_stdin_used+0x72>
 8048686:	73 20                	jae    80486a8 <_IO_stdin_used+0x2c>
 8048688:	53                   	push   %ebx
 8048689:	49                   	dec    %ecx
 804868a:	47                   	inc    %edi
 804868b:	43                   	inc    %ebx
 804868c:	48                   	dec    %eax
 804868d:	4c                   	dec    %esp
 804868e:	44                   	inc    %esp
 804868f:	20 73 69             	and    %dh,0x69(%ebx)
 8048692:	67 6e                	outsb  %ds:(%si),(%dx)
 8048694:	61                   	popa   
 8048695:	6c                   	insb   (%dx),%es:(%edi)
 8048696:	00 63 61             	add    %ah,0x61(%ebx)
 8048699:	74 63                	je     80486fe <_IO_stdin_used+0x82>
 804869b:	68 20 74 68 65       	push   $0x65687420
 80486a0:	20 73 69             	and    %dh,0x69(%ebx)
 80486a3:	6e                   	outsb  %ds:(%esi),(%dx)
 80486a4:	61                   	popa   
 80486a5:	6c                   	insb   (%dx),%es:(%edi)
 80486a6:	20 3a                	and    %bh,(%edx)
 80486a8:	25 64 0a 00 66       	and    $0x66000a64,%eax
 80486ad:	6f                   	outsl  %ds:(%esi),(%dx)
 80486ae:	72 6b                	jb     804871b <_IO_stdin_used+0x9f>
 80486b0:	20 66 61             	and    %ah,0x61(%esi)
 80486b3:	69 6c 65 64 21 00 74 	imul   $0x68740021,0x64(%ebp,%eiz,2),%ebp
 80486ba:	68 
 80486bb:	65 20 63 68          	and    %ah,%gs:0x68(%ebx)
 80486bf:	69 6c 64 20 70 72 6f 	imul   $0x636f7270,0x20(%esp,%eiz,2),%ebp
 80486c6:	63 
 80486c7:	65                   	gs
 80486c8:	73 73                	jae    804873d <_IO_stdin_used+0xc1>
 80486ca:	21 00                	and    %eax,(%eax)
 80486cc:	74 68                	je     8048736 <_IO_stdin_used+0xba>
 80486ce:	65 20 66 61          	and    %ah,%gs:0x61(%esi)
 80486d2:	74 68                	je     804873c <_IO_stdin_used+0xc0>
 80486d4:	65                   	gs
 80486d5:	72 20                	jb     80486f7 <_IO_stdin_used+0x7b>
 80486d7:	70 72                	jo     804874b <_IO_stdin_used+0xcf>
 80486d9:	6f                   	outsl  %ds:(%esi),(%dx)
 80486da:	63 65 73             	arpl   %sp,0x73(%ebp)
 80486dd:	73 21                	jae    8048700 <_IO_stdin_used+0x84>
 80486df:	00 63 68             	add    %ah,0x68(%ebx)
 80486e2:	69 6c 64 20 68 61 73 	imul   $0x20736168,0x20(%esp,%eiz,2),%ebp
 80486e9:	20 
 80486ea:	65                   	gs
 80486eb:	78 69                	js     8048756 <_IO_stdin_used+0xda>
 80486ed:	74 21                	je     8048710 <_IO_stdin_used+0x94>
 80486ef:	00 69 6e             	add    %ch,0x6e(%ecx)
 80486f2:	73 74                	jae    8048768 <_IO_stdin_used+0xec>
 80486f4:	61                   	popa   
 80486f5:	6c                   	insb   (%dx),%es:(%edi)
 80486f6:	6c                   	insb   (%dx),%es:(%edi)
 80486f7:	20 73 69             	and    %dh,0x69(%ebx)
 80486fa:	67 6e                	outsb  %ds:(%si),(%dx)
 80486fc:	61                   	popa   
 80486fd:	6c                   	insb   (%dx),%es:(%edi)
 80486fe:	20 73 75             	and    %dh,0x75(%ebx)
 8048701:	63 63 65             	arpl   %sp,0x65(%ebx)
 8048704:	73 73                	jae    8048779 <_IO_stdin_used+0xfd>
 8048706:	65 64 21 00          	gs and %eax,%fs:%gs:(%eax)

Disassembly of section .eh_frame_hdr:

0804870c <.eh_frame_hdr>:
 804870c:	01 1b                	add    %ebx,(%ebx)
 804870e:	03 3b                	add    (%ebx),%edi
 8048710:	20 00                	and    %al,(%eax)
 8048712:	00 00                	add    %al,(%eax)
 8048714:	03 00                	add    (%eax),%eax
 8048716:	00 00                	add    %al,(%eax)
 8048718:	94                   	xchg   %eax,%esp
 8048719:	fc                   	cld    
 804871a:	ff                   	(bad)  
 804871b:	ff                   	(bad)  
 804871c:	3c 00                	cmp    $0x0,%al
 804871e:	00 00                	add    %al,(%eax)
 8048720:	10 fe                	adc    %bh,%dh
 8048722:	ff                   	(bad)  
 8048723:	ff 60 00             	jmp    *0x0(%eax)
 8048726:	00 00                	add    %al,(%eax)
 8048728:	40                   	inc    %eax
 8048729:	fe                   	(bad)  
 804872a:	ff                   	(bad)  
 804872b:	ff                   	.byte 0xff
 804872c:	80 00 00             	addb   $0x0,(%eax)
	...

Disassembly of section .eh_frame:

08048730 <__FRAME_END__-0x7c>:
 8048730:	14 00                	adc    $0x0,%al
 8048732:	00 00                	add    %al,(%eax)
 8048734:	00 00                	add    %al,(%eax)
 8048736:	00 00                	add    %al,(%eax)
 8048738:	01 7a 52             	add    %edi,0x52(%edx)
 804873b:	00 01                	add    %al,(%ecx)
 804873d:	7c 08                	jl     8048747 <_IO_stdin_used+0xcb>
 804873f:	01 1b                	add    %ebx,(%ebx)
 8048741:	0c 04                	or     $0x4,%al
 8048743:	04 88                	add    $0x88,%al
 8048745:	01 00                	add    %eax,(%eax)
 8048747:	00 20                	add    %ah,(%eax)
 8048749:	00 00                	add    %al,(%eax)
 804874b:	00 1c 00             	add    %bl,(%eax,%eax,1)
 804874e:	00 00                	add    %al,(%eax)
 8048750:	50                   	push   %eax
 8048751:	fc                   	cld    
 8048752:	ff                   	(bad)  
 8048753:	ff 90 00 00 00 00    	call   *0x0(%eax)
 8048759:	0e                   	push   %cs
 804875a:	08 46 0e             	or     %al,0xe(%esi)
 804875d:	0c 4a                	or     $0x4a,%al
 804875f:	0f 0b                	ud2    
 8048761:	74 04                	je     8048767 <_IO_stdin_used+0xeb>
 8048763:	78 00                	js     8048765 <_IO_stdin_used+0xe9>
 8048765:	3f                   	aas    
 8048766:	1a 3b                	sbb    (%ebx),%bh
 8048768:	2a 32                	sub    (%edx),%dh
 804876a:	24 22                	and    $0x22,%al
 804876c:	1c 00                	sbb    $0x0,%al
 804876e:	00 00                	add    %al,(%eax)
 8048770:	40                   	inc    %eax
 8048771:	00 00                	add    %al,(%eax)
 8048773:	00 a8 fd ff ff 30    	add    %ch,0x30fffffd(%eax)
 8048779:	00 00                	add    %al,(%eax)
 804877b:	00 00                	add    %al,(%eax)
 804877d:	41                   	inc    %ecx
 804877e:	0e                   	push   %cs
 804877f:	08 85 02 42 0d 05    	or     %al,0x50d4202(%ebp)
 8048785:	6c                   	insb   (%dx),%es:(%edi)
 8048786:	c5 0c 04             	lds    (%esp,%eax,1),%ecx
 8048789:	04 00                	add    $0x0,%al
 804878b:	00 1c 00             	add    %bl,(%eax,%eax,1)
 804878e:	00 00                	add    %al,(%eax)
 8048790:	60                   	pusha  
 8048791:	00 00                	add    %al,(%eax)
 8048793:	00 b8 fd ff ff 9d    	add    %bh,-0x62000003(%eax)
 8048799:	00 00                	add    %al,(%eax)
 804879b:	00 00                	add    %al,(%eax)
 804879d:	41                   	inc    %ecx
 804879e:	0e                   	push   %cs
 804879f:	08 85 02 42 0d 05    	or     %al,0x50d4202(%ebp)
 80487a5:	02 99 c5 0c 04 04    	add    0x4040cc5(%ecx),%bl
	...

080487ac <__FRAME_END__>:
 80487ac:	00 00                	add    %al,(%eax)
	...

Disassembly of section .init_array:

080497b0 <__frame_dummy_init_array_entry>:
 80497b0:	f0 84 04 08          	lock test %al,(%eax,%ecx,1)

Disassembly of section .fini_array:

080497b4 <__do_global_dtors_aux_fini_array_entry>:
 80497b4:	d0                   	.byte 0xd0
 80497b5:	84 04 08             	test   %al,(%eax,%ecx,1)

Disassembly of section .jcr:

080497b8 <__JCR_END__>:
 80497b8:	00 00                	add    %al,(%eax)
	...

Disassembly of section .dynamic:

080497bc <_DYNAMIC>:
 80497bc:	01 00                	add    %eax,(%eax)
 80497be:	00 00                	add    %al,(%eax)
 80497c0:	10 00                	adc    %al,(%eax)
 80497c2:	00 00                	add    %al,(%eax)
 80497c4:	0c 00                	or     $0x0,%al
 80497c6:	00 00                	add    %al,(%eax)
 80497c8:	6c                   	insb   (%dx),%es:(%edi)
 80497c9:	83 04 08 0d          	addl   $0xd,(%eax,%ecx,1)
 80497cd:	00 00                	add    %al,(%eax)
 80497cf:	00 60 86             	add    %ah,-0x7a(%eax)
 80497d2:	04 08                	add    $0x8,%al
 80497d4:	19 00                	sbb    %eax,(%eax)
 80497d6:	00 00                	add    %al,(%eax)
 80497d8:	b0 97                	mov    $0x97,%al
 80497da:	04 08                	add    $0x8,%al
 80497dc:	1b 00                	sbb    (%eax),%eax
 80497de:	00 00                	add    %al,(%eax)
 80497e0:	04 00                	add    $0x0,%al
 80497e2:	00 00                	add    %al,(%eax)
 80497e4:	1a 00                	sbb    (%eax),%al
 80497e6:	00 00                	add    %al,(%eax)
 80497e8:	b4 97                	mov    $0x97,%ah
 80497ea:	04 08                	add    $0x8,%al
 80497ec:	1c 00                	sbb    $0x0,%al
 80497ee:	00 00                	add    %al,(%eax)
 80497f0:	04 00                	add    $0x0,%al
 80497f2:	00 00                	add    %al,(%eax)
 80497f4:	04 00                	add    $0x0,%al
 80497f6:	00 00                	add    %al,(%eax)
 80497f8:	8c 81 04 08 f5 fe    	mov    %es,-0x10af7fc(%ecx)
 80497fe:	ff 6f c8             	ljmp   *-0x38(%edi)
 8049801:	81 04 08 05 00 00 00 	addl   $0x5,(%eax,%ecx,1)
 8049808:	88 82 04 08 06 00    	mov    %al,0x60804(%edx)
 804980e:	00 00                	add    %al,(%eax)
 8049810:	e8 81 04 08 0a       	call   120c9c96 <_end+0xa0803ae>
 8049815:	00 00                	add    %al,(%eax)
 8049817:	00 68 00             	add    %ch,0x0(%eax)
 804981a:	00 00                	add    %al,(%eax)
 804981c:	0b 00                	or     (%eax),%eax
 804981e:	00 00                	add    %al,(%eax)
 8049820:	10 00                	adc    %al,(%eax)
 8049822:	00 00                	add    %al,(%eax)
 8049824:	15 00 00 00 00       	adc    $0x0,%eax
 8049829:	00 00                	add    %al,(%eax)
 804982b:	00 03                	add    %al,(%ebx)
 804982d:	00 00                	add    %al,(%eax)
 804982f:	00 b0 98 04 08 02    	add    %dh,0x2080498(%eax)
 8049835:	00 00                	add    %al,(%eax)
 8049837:	00 40 00             	add    %al,0x0(%eax)
 804983a:	00 00                	add    %al,(%eax)
 804983c:	14 00                	adc    $0x0,%al
 804983e:	00 00                	add    %al,(%eax)
 8049840:	11 00                	adc    %eax,(%eax)
 8049842:	00 00                	add    %al,(%eax)
 8049844:	17                   	pop    %ss
 8049845:	00 00                	add    %al,(%eax)
 8049847:	00 2c 83             	add    %ch,(%ebx,%eax,4)
 804984a:	04 08                	add    $0x8,%al
 804984c:	11 00                	adc    %eax,(%eax)
 804984e:	00 00                	add    %al,(%eax)
 8049850:	24 83                	and    $0x83,%al
 8049852:	04 08                	add    $0x8,%al
 8049854:	12 00                	adc    (%eax),%al
 8049856:	00 00                	add    %al,(%eax)
 8049858:	08 00                	or     %al,(%eax)
 804985a:	00 00                	add    %al,(%eax)
 804985c:	13 00                	adc    (%eax),%eax
 804985e:	00 00                	add    %al,(%eax)
 8049860:	08 00                	or     %al,(%eax)
 8049862:	00 00                	add    %al,(%eax)
 8049864:	fe                   	(bad)  
 8049865:	ff                   	(bad)  
 8049866:	ff 6f 04             	ljmp   *0x4(%edi)
 8049869:	83 04 08 ff          	addl   $0xffffffff,(%eax,%ecx,1)
 804986d:	ff                   	(bad)  
 804986e:	ff 6f 01             	ljmp   *0x1(%edi)
 8049871:	00 00                	add    %al,(%eax)
 8049873:	00 f0                	add    %dh,%al
 8049875:	ff                   	(bad)  
 8049876:	ff 6f f0             	ljmp   *-0x10(%edi)
 8049879:	82                   	(bad)  
 804987a:	04 08                	add    $0x8,%al
	...

Disassembly of section .got:

080498ac <.got>:
 80498ac:	00 00                	add    %al,(%eax)
	...

Disassembly of section .got.plt:

080498b0 <_GLOBAL_OFFSET_TABLE_>:
 80498b0:	bc 97 04 08 00       	mov    $0x80497,%esp
 80498b5:	00 00                	add    %al,(%eax)
 80498b7:	00 00                	add    %al,(%eax)
 80498b9:	00 00                	add    %al,(%eax)
 80498bb:	00 b6 83 04 08 c6    	add    %dh,-0x39f7fb7d(%esi)
 80498c1:	83 04 08 d6          	addl   $0xffffffd6,(%eax,%ecx,1)
 80498c5:	83 04 08 e6          	addl   $0xffffffe6,(%eax,%ecx,1)
 80498c9:	83 04 08 f6          	addl   $0xfffffff6,(%eax,%ecx,1)
 80498cd:	83 04 08 06          	addl   $0x6,(%eax,%ecx,1)
 80498d1:	84 04 08             	test   %al,(%eax,%ecx,1)
 80498d4:	16                   	push   %ss
 80498d5:	84 04 08             	test   %al,(%eax,%ecx,1)
 80498d8:	26 84 04 08          	test   %al,%es:(%eax,%ecx,1)

Disassembly of section .data:

080498dc <__data_start>:
 80498dc:	00 00                	add    %al,(%eax)
	...

080498e0 <__dso_handle>:
 80498e0:	00 00                	add    %al,(%eax)
	...

Disassembly of section .bss:

080498e4 <completed.5730>:
 80498e4:	00 00                	add    %al,(%eax)
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	47                   	inc    %edi
   1:	43                   	inc    %ebx
   2:	43                   	inc    %ebx
   3:	3a 20                	cmp    (%eax),%ah
   5:	28 44 65 62          	sub    %al,0x62(%ebp,%eiz,2)
   9:	69 61 6e 20 34 2e 37 	imul   $0x372e3420,0x6e(%ecx),%esp
  10:	2e 32 2d 35 29 20 34 	xor    %cs:0x34202935,%ch
  17:	2e                   	cs
  18:	37                   	aaa    
  19:	2e 32 00             	xor    %cs:(%eax),%al
  1c:	47                   	inc    %edi
  1d:	43                   	inc    %ebx
  1e:	43                   	inc    %ebx
  1f:	3a 20                	cmp    (%eax),%ah
  21:	28 44 65 62          	sub    %al,0x62(%ebp,%eiz,2)
  25:	69 61 6e 20 34 2e 34 	imul   $0x342e3420,0x6e(%ecx),%esp
  2c:	2e                   	cs
  2d:	37                   	aaa    
  2e:	2d 32 29 20 34       	sub    $0x34202932,%eax
  33:	2e                   	cs
  34:	34 2e                	xor    $0x2e,%al
  36:	37                   	aaa    
	...
