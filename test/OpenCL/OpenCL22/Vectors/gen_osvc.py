import collections
import itertools
import random

#        ext name       require pragma enable
exts = [
        ('cl_khr_fp16', 1),
        ('cl_khr_fp64', 0)
    ]
#        vec elem type  required ext     rank  fp  sign  enabled as
#                                                        vec scalar
elemTys = [
        ('bool',        [],                 1,  0,   0,  0,  1), #  0
        ('uchar',       [],                 8,  0,   0,  1,  1), #  1
        ('char',        [],                 8,  0,   1,  1,  1), #  2
        ('ushort',      [],                16,  0,   0,  1,  1), #  3
        ('short',       [],                16,  0,   1,  1,  1), #  4
        ('uint',        [],                32,  0,   0,  1,  1), #  5
        ('int',         [],                32,  0,   1,  1,  1), #  6
        ('ulong',       [],                64,  0,   0,  1,  1), #  7
        ('long',        [],                64,  0,   1,  1,  1), #  8
        ('half',        ['cl_khr_fp16'],   10,  1,   1,  1,  1), #  9
        ('float',       [],                23,  1,   1,  1,  1), # 10
        ('double',      ['cl_khr_fp64'],   52,  1,   1,  1,  1), # 11
    ]
#        literal text                    required ext      convertible without narrowing
#                                                                              1 1
#                                                          0 1 2 3 4 5 6 7 8 9 0 1
scalars = [
        ('true',                         [],              [1,1,1,1,1,1,1,1,1,1,1,1]),
        ('false',                        [],              [1,1,1,1,1,1,1,1,1,1,1,1]),

        ("'\\0'",                        [],              [1,1,1,1,1,1,1,1,1,1,1,1]),
        ('\'A\'',                        [],              [0,1,1,1,1,1,1,1,1,1,1,1]),
        ('static_cast<char>(-12)',       [],              [0,0,1,0,1,0,1,0,1,1,1,1]),
        ('static_cast<uchar>(\'A\')',    [],              [0,1,1,1,1,1,1,1,1,1,1,1]),
        ('static_cast<uchar>(145)',      [],              [0,1,0,1,1,1,1,1,1,1,1,1]),
        
        ('static_cast<short>(145)',      [],              [0,1,0,1,1,1,1,1,1,1,1,1]),
        ('static_cast<short>(14501)',    [],              [0,0,0,1,1,1,1,1,1,0,1,1]),
        ('static_cast<short>(-17501)',   [],              [0,0,0,0,1,0,1,0,1,0,1,1]),
        ('static_cast<ushort>(34501)',   [],              [0,0,0,1,0,1,1,1,1,0,1,1]),

        ('1',                            [],              [1,1,1,1,1,1,1,1,1,1,1,1]),
        ('10',                           [],              [0,1,1,1,1,1,1,1,1,1,1,1]),
        ('-10',                          [],              [0,0,1,0,1,0,1,0,1,1,1,1]),
        ('100001',                       [],              [0,0,0,0,0,1,1,1,1,0,1,1]),
        ('-100001',                      [],              [0,0,0,0,0,0,1,0,1,0,1,1]),
        ('100000001',                    [],              [0,0,0,0,0,1,1,1,1,0,0,1]),
        ('-100000001',                   [],              [0,0,0,0,0,0,1,0,1,0,0,1]),

        ('100000000001',                 [],              [0,0,0,0,0,0,0,1,1,0,0,1]),
        ('-100000000001',                [],              [0,0,0,0,0,0,0,0,1,0,0,1]),
        ('100000000001UL',               [],              [0,0,0,0,0,0,0,1,1,0,0,1]),
        ('-100000000001L',               [],              [0,0,0,0,0,0,0,0,1,0,0,1]),

        ('static_cast<half>(1.0f)',      ['cl_khr_fp16'], [1,1,1,1,1,1,1,1,1,1,1,1]),
        ('static_cast<half>(12.0f)',     ['cl_khr_fp16'], [0,1,1,1,1,1,1,1,1,1,1,1]),
        ('static_cast<half>(-12.0f)',    ['cl_khr_fp16'], [0,0,1,0,1,0,1,0,1,1,1,1]),
        ('static_cast<half>(12.25f)',    ['cl_khr_fp16'], [0,0,0,0,0,0,0,0,0,1,1,1]),
        ('static_cast<half>(-12.25f)',   ['cl_khr_fp16'], [0,0,0,0,0,0,0,0,0,1,1,1]),

        ('1.0f',                         [],              [1,1,1,1,1,1,1,1,1,1,1,1]),
        ('12.0f',                        [],              [0,1,1,1,1,1,1,1,1,1,1,1]),
        ('-12.0f',                       [],              [0,0,1,0,1,0,1,0,1,1,1,1]),
        ('12.25f',                       [],              [0,0,0,0,0,0,0,0,0,1,1,1]),
        ('-12.25f',                      [],              [0,0,0,0,0,0,0,0,0,1,1,1]),
        ('123456.f',                     [],              [0,0,0,0,0,1,1,1,1,0,1,1]),
        ('123456.25f',                   [],              [0,0,0,0,0,0,0,0,0,0,1,1]),
        
        ('1.0',                          ['cl_khr_fp64'], [1,1,1,1,1,1,1,1,1,1,1,1]),
        ('12.0',                         ['cl_khr_fp64'], [0,1,1,1,1,1,1,1,1,1,1,1]),
        ('-12.0',                        ['cl_khr_fp64'], [0,0,1,0,1,0,1,0,1,1,1,1]),
        ('12.25',                        ['cl_khr_fp64'], [0,0,0,0,0,0,0,0,0,1,1,1]),
        ('-12.25',                       ['cl_khr_fp64'], [0,0,0,0,0,0,0,0,0,1,1,1]),
        ('123456.',                      ['cl_khr_fp64'], [0,0,0,0,0,1,1,1,1,0,1,1]),
        ('123456.25',                    ['cl_khr_fp64'], [0,0,0,0,0,0,0,0,0,0,1,1]),
        ('-123456789.',                  ['cl_khr_fp64'], [0,0,0,0,0,0,1,0,1,0,1,1]), # prec loss on float is not narrowing (only overflow)
        ('-123456789.25',                ['cl_khr_fp64'], [0,0,0,0,0,0,0,0,0,0,1,1]), # prec loss on float constant is not narrowing (only overflow)
        ('-123456789.25e40',             ['cl_khr_fp64'], [0,0,0,0,0,0,0,0,0,0,0,1]), # prec loss on float constant is not narrowing (only overflow)
    ]
vectorSizes = [2, 3, 4, 8, 16]
vecQualifiers = [
        '               %(type)-8s   ',
        'const          %(type)-8s   ',
        'volatile       %(type)-8s   ',
        'const volatile %(type)-8s   ',
        '               %(type)-8s &&',
        'const          %(type)-8s  &',
        'const          %(type)-8s &&',
        'volatile       %(type)-8s &&',
        'const volatile %(type)-8s &&'
    ]
scalarQualifiers = [
        '               %(type)-8s   ',
        'volatile       %(type)-8s   ',
        '               %(type)-8s &&',
        'const          %(type)-8s  &',
        'const          %(type)-8s &&',
        'volatile       %(type)-8s &&',
        'const volatile %(type)-8s &&'
    ]



headerTemplate = '''%(runHeader)s



%(extEnable)s

#include <opencl_work_item>

'''
runHeaderTemplate = '// RUN: %%clang_cc1 %%s -triple spir-unknown-unknown -cl-std=CL2.1 -pedantic -O0 -Wall -Wno-unused-variable -verify %(runHeaderDecl)s -emit-llvm -o -'
runHeaderDeclTemplate = '-D%(ext)s'
runHeaderDeclSep = ' '

extEnableTemplate = '''#ifdef %(ext)s
    #pragma OPENCL EXTENSION %(ext)s: enable
#endif // %(ext)s'''
extSectionBeginTemplate = '#ifdef %(ext)s'
extSectionEndTemplate = '#endif // %(ext)s'

kernelTemplate = '''kernel void %(kernelName)s()
{
    // Vectors and vector references.
%(vecDecls)s
    
    // Scalars and scalar references.
%(scalarDecls)s

    // Scalar to vector conversion (variables).
%(variableOps)s

    // Scalar to vector conversion (literals).
%(literalOps)s
}'''

vecTypeTemplate = '%(elemTy)s%(vecSize)s'
vecNameTemplate = 'vec%(varId)03d'
vecDeclTemplate = '%(qualType)s %(varName)s = %(type)s();'

scalarNameTemplate = 'sv%(varId)03d'
scalarDeclTemplate = '%(qualType)s %(varName)s = %(type)s();'

opResultNameTemplate = 'r%(varId)04d'
opTemplate = '%(enabled)s%(resType)-8s %(resName)s = %(op1Name)s + %(op2Name)s;%(expIssue)s'
opExpNarrowVariable = ' // expected-warning-re {{non-constant-expression is narrowed from type {{.*}} to {{.*}} during scalar-to-vector conversion}} expected-note {{insert an explicit cast of scalar to}}'
opExpNarrowLiteral  = ' // expected-warning-re {{constant expression evaluates to {{.*}} which cannot be narrowed to type {{.*}} during scalar-to-vector conversion}} expected-note {{insert an explicit cast of scalar to}} expected-warning-re 0-1 {{implicit conversion from {{.*}} to {{.*}} changes value}}'

codeSep = '''
'''
codeIndent = '    '
opsPerOpPair = 2
declPerElemTy = 2


def indent(str, lvl = 1):
    lines = str.splitlines()
    indentedLines = [codeIndent * (len(line) > 0) * lvl + line for line in lines]
    return codeSep.join(indentedLines)

def generateHeader():
    runHeaders = []
    for extSize in xrange(len(exts) + 1):
        for extSubSet in itertools.combinations(exts, extSize):
            runHeaders.append(runHeaderTemplate % {'runHeaderDecl': runHeaderDeclSep.join([(runHeaderDeclTemplate % {'ext': ext[0]}) for ext in extSubSet])})
    extEnable = codeSep.join([(extEnableTemplate % {'ext': ext[0]}) for ext in extSubSet if ext[1]])
    return headerTemplate % {'runHeader': codeSep.join(runHeaders), 'extEnable': extEnable}

def generateExtSectionBegin(ext):
    return extSectionBeginTemplate % {'ext' : ext}

def generateExtSectionEnd(ext):
    return extSectionEndTemplate % {'ext' : ext}

def changeExtState(out, currentState, updatedState = []):
    if currentState == updatedState:
        return currentState
    
    stateDiffIdx = min(len(currentState), len(updatedState))
    for si in xrange(min(len(currentState), len(updatedState))):
        if currentState[si] != updatedState[si]:
            stateDiffIdx = si
            break
        
    stateToRemove = currentState[stateDiffIdx:]
    stateToRemove.reverse()
    stateToAdd = updatedState[stateDiffIdx:]
    
    for extToRemove in stateToRemove:
        out.append(generateExtSectionEnd(extToRemove))
    for extToAdd in stateToAdd:
        out.append(generateExtSectionBegin(extToAdd))

    return updatedState

def generateVecType(rnd, elemTyIdx):
    elemTyName = elemTys[elemTyIdx][0]
    vecSize = rnd.choice(vectorSizes)
    vecType = vecTypeTemplate % {'elemTy': elemTyName, 'vecSize': vecSize}
    qualVecType = rnd.choice(vecQualifiers) % {'type': vecType}
    
    return (elemTyIdx, vecSize, vecType, qualVecType)
        
def generateVecDecls(rnd, repeat = 1):
    elemTyIdxs, varSizes, varTypes, qualVarTypes = zip(*[generateVecType(rnd, ei) for ei in xrange(len(elemTys)) for ri in xrange(repeat)])
    varDecls = []
    varInfos = collections.defaultdict(list)
    extState = []
    for di in xrange(len(varTypes)):
        elemTyExts = elemTys[elemTyIdxs[di]][1]
        varName = vecNameTemplate % {'varId': di + 1}
        varInfos[elemTyIdxs[di]].append((varName, varTypes[di], varSizes[di]))
        extState = changeExtState(varDecls, extState, elemTyExts)
        varDecls.append(vecDeclTemplate % {'qualType': qualVarTypes[di], 'varName': varName, 'type': varTypes[di]})
    extState = changeExtState(varDecls, extState)
        
    return (dict(varInfos), codeSep.join(varDecls))

def generateScalarType(rnd, elemTyIdx):
    elemTyName = elemTys[elemTyIdx][0]
    scalarType = elemTyName
    qualScalarType = rnd.choice(scalarQualifiers) % {'type': scalarType}
    
    return (elemTyIdx, scalarType, qualScalarType)

def generateScalarDecls(rnd, repeat = 1):
    elemTyIdxs, varTypes, qualVarTypes = zip(*[generateScalarType(rnd, ei) for ei in xrange(len(elemTys)) for ri in xrange(repeat)])
    varDecls = []
    varInfos = collections.defaultdict(list)
    extState = []
    for di in xrange(len(varTypes)):
        elemTyExts = elemTys[elemTyIdxs[di]][1]
        varName = scalarNameTemplate % {'varId': di + 1}
        varInfos[elemTyIdxs[di]].append((varName, varTypes[di]))
        extState = changeExtState(varDecls, extState, elemTyExts)
        varDecls.append(scalarDeclTemplate % {'qualType': qualVarTypes[di], 'varName': varName, 'type': varTypes[di]})
    extState = changeExtState(varDecls, extState)
        
    return (dict(varInfos), codeSep.join(varDecls))


def isVariableNarrowing(vecTyIdx, scalarTyIdx):
    vecElemTy    = elemTys[vecTyIdx]
    scalarElemTy = elemTys[scalarTyIdx]

    if scalarElemTy[3] != 0 and vecElemTy[3] == 0: # converting floating point to integer variable is always narrowing
        return True
    if scalarElemTy[4] != 0 and vecElemTy[4] == 0: # converting signed to unsigned variable is always narrowing
        return True
    if scalarElemTy[2] > vecElemTy[2]: # converting from greater rank to lower rank variable is always narrowing
        return True
    if scalarElemTy[2] == vecElemTy[2] and scalarElemTy[3] == vecElemTy[3] and scalarElemTy[4] != vecElemTy[4]: # converting variable to signed (the same rank and type) is always narrowing
        return True
    return False
    

def generateVariableOp(rnd, vecInfos, scalarInfos, vecTyIdx, scalarTyIdx, opId):
    vecInfo = vecInfos[vecTyIdx]
    scalarInfo = scalarInfos[scalarTyIdx]
    opVecInfo = vecInfo[opId % len(vecInfo)]
    opScalarInfo = scalarInfo[opId % len(scalarInfo)]
    if opId % 2 == 0:
        op1Info = opVecInfo
        op2Info = opScalarInfo
    else:
        op2Info = opVecInfo
        op1Info = opScalarInfo
    opResultType = [
            'auto',
            opVecInfo[1]
        ]
    opResultName = opResultNameTemplate % {'varId': opId + 1}
    enabled = elemTys[vecTyIdx][5] != 0 and elemTys[scalarTyIdx][6] != 0
    opExpIssue = opExpNarrowVariable if isVariableNarrowing(vecTyIdx, scalarTyIdx) and enabled else ''
    opEnabled = '' if enabled else '// '
    return opTemplate % {'enabled': opEnabled, 'resType': rnd.choice(opResultType), 'resName': opResultName, 'op1Name': op1Info[0], 'op2Name': op2Info[0], 'expIssue': opExpIssue}

def generateVariableOps(rnd, vecInfos, scalarInfos, opId = 0):
    ops = []
    extState = []
    for vi in xrange(len(elemTys)):
        for si in xrange(len(elemTys)):
            for oi in xrange(opsPerOpPair):
                opExts = list(set(elemTys[vi][1] + elemTys[si][1]))
                extState = changeExtState(ops, extState, opExts)
                ops.append(generateVariableOp(rnd, vecInfos, scalarInfos, vi, si, opId))
                opId += 1
    extState = changeExtState(ops, extState)
    
    return (codeSep.join(ops), opId)

def isLiteralNarrowing(vecTyIdx, scalarLiteralIdx):
    scalarLiteral = scalars[scalarLiteralIdx]

    if len(scalarLiteral[2]) != len(elemTys) or vecTyIdx >= len(scalarLiteral[2]):
        raise RuntimeError()

    return not scalarLiteral[2][vecTyIdx]

def generateLiteralOp(rnd, vecInfos, vecTyIdx, scalarLiteralIdx, opId):
    vecInfo = vecInfos[vecTyIdx]
    scalarLiteral = scalars[scalarLiteralIdx]
    opVecInfo = vecInfo[opId % len(vecInfo)]
    if opId % 2 == 0:
        op1Info = opVecInfo
        op2Info = scalarLiteral
    else:
        op2Info = opVecInfo
        op1Info = scalarLiteral
    opResultType = [
            'auto',
            opVecInfo[1]
        ]
    opResultName = opResultNameTemplate % {'varId': opId + 1}
    enabled = elemTys[vecTyIdx][5] != 0
    opExpIssue = opExpNarrowLiteral if isLiteralNarrowing(vecTyIdx, scalarLiteralIdx) and enabled else ''
    opEnabled = '' if enabled else '// '
    return opTemplate % {'enabled': opEnabled, 'resType': rnd.choice(opResultType), 'resName': opResultName, 'op1Name': op1Info[0], 'op2Name': op2Info[0], 'expIssue': opExpIssue}

def generateLiteralOps(rnd, vecInfos, opId = 0):
    ops = []
    extState = []
    for vi in xrange(len(elemTys)):
        for si in xrange(len(scalars)):
            for oi in xrange(opsPerOpPair):
                opExts = list(set(elemTys[vi][1] + scalars[si][1]))
                extState = changeExtState(ops, extState, opExts)
                ops.append(generateLiteralOp(rnd, vecInfos, vi, si, opId))
                opId += 1
    extState = changeExtState(ops, extState)
    
    return (codeSep.join(ops), opId)

def generateKernel(rnd, name = 'worker'):
    vecDecls = generateVecDecls(rnd, declPerElemTy)
    scalarDecls = generateScalarDecls(rnd, declPerElemTy)
    variableOps, opId = generateVariableOps(rnd, vecDecls[0], scalarDecls[0])
    literalOps, opId = generateLiteralOps(rnd, vecDecls[0], opId)
    
    return kernelTemplate % {'kernelName': name, 'vecDecls': indent(vecDecls[1]), 'scalarDecls': indent(scalarDecls[1]), 'variableOps': indent(variableOps), 'literalOps': indent(literalOps)}



rnd = random.Random(1234567)
print generateHeader()
print generateKernel(rnd)

