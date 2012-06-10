@echo off
REM Generated by niminst
SET CC=gcc
SET LINKER=gcc
SET COMP_FLAGS=-w -g3 -O0 -O3 -fno-strict-aliasing
SET LINK_FLAGS=

REM call the compiler:

ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\nim__dat.c -o build\1_1\nim__dat.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\nim__dat.c -o build\1_1\nim__dat.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\system.c -o build\1_1\system.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\system.c -o build\1_1\system.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\nimrod.c -o build\1_1\nimrod.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\nimrod.c -o build\1_1\nimrod.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\times.c -o build\1_1\times.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\times.c -o build\1_1\times.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\strutils.c -o build\1_1\strutils.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\strutils.c -o build\1_1\strutils.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\parseutils.c -o build\1_1\parseutils.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\parseutils.c -o build\1_1\parseutils.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\winlean.c -o build\1_1\winlean.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\winlean.c -o build\1_1\winlean.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\commands.c -o build\1_1\commands.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\commands.c -o build\1_1\commands.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\os.c -o build\1_1\os.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\os.c -o build\1_1\os.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\msgs.c -o build\1_1\msgs.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\msgs.c -o build\1_1\msgs.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\options.c -o build\1_1\options.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\options.c -o build\1_1\options.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\lists.c -o build\1_1\lists.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\lists.c -o build\1_1\lists.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\strtabs.c -o build\1_1\strtabs.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\strtabs.c -o build\1_1\strtabs.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\hashes.c -o build\1_1\hashes.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\hashes.c -o build\1_1\hashes.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\tables.c -o build\1_1\tables.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\tables.c -o build\1_1\tables.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\math.c -o build\1_1\math.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\math.c -o build\1_1\math.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\nversion.c -o build\1_1\nversion.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\nversion.c -o build\1_1\nversion.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\condsyms.c -o build\1_1\condsyms.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\condsyms.c -o build\1_1\condsyms.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\ast.c -o build\1_1\ast.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\ast.c -o build\1_1\ast.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\crc.c -o build\1_1\crc.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\crc.c -o build\1_1\crc.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\ropes.c -o build\1_1\ropes.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\ropes.c -o build\1_1\ropes.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\platform.c -o build\1_1\platform.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\platform.c -o build\1_1\platform.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\idents.c -o build\1_1\idents.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\idents.c -o build\1_1\idents.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\intsets.c -o build\1_1\intsets.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\intsets.c -o build\1_1\intsets.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\idgen.c -o build\1_1\idgen.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\idgen.c -o build\1_1\idgen.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\astalgo.c -o build\1_1\astalgo.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\astalgo.c -o build\1_1\astalgo.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\rodutils.c -o build\1_1\rodutils.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\rodutils.c -o build\1_1\rodutils.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\extccomp.c -o build\1_1\extccomp.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\extccomp.c -o build\1_1\extccomp.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\osproc.c -o build\1_1\osproc.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\osproc.c -o build\1_1\osproc.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\streams.c -o build\1_1\streams.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\streams.c -o build\1_1\streams.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\wordrecg.c -o build\1_1\wordrecg.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\wordrecg.c -o build\1_1\wordrecg.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\lexer.c -o build\1_1\lexer.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\lexer.c -o build\1_1\lexer.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\lexbase.c -o build\1_1\lexbase.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\lexbase.c -o build\1_1\lexbase.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\llstream.c -o build\1_1\llstream.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\llstream.c -o build\1_1\llstream.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\nimconf.c -o build\1_1\nimconf.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\nimconf.c -o build\1_1\nimconf.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\main.c -o build\1_1\main.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\main.c -o build\1_1\main.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\syntaxes.c -o build\1_1\syntaxes.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\syntaxes.c -o build\1_1\syntaxes.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\parser.c -o build\1_1\parser.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\parser.c -o build\1_1\parser.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\pbraces.c -o build\1_1\pbraces.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\pbraces.c -o build\1_1\pbraces.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\filters.c -o build\1_1\filters.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\filters.c -o build\1_1\filters.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\renderer.c -o build\1_1\renderer.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\renderer.c -o build\1_1\renderer.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\filter_tmpl.c -o build\1_1\filter_tmpl.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\filter_tmpl.c -o build\1_1\filter_tmpl.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\rodread.c -o build\1_1\rodread.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\rodread.c -o build\1_1\rodread.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\memfiles.c -o build\1_1\memfiles.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\memfiles.c -o build\1_1\memfiles.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\rodwrite.c -o build\1_1\rodwrite.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\rodwrite.c -o build\1_1\rodwrite.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\passes.c -o build\1_1\passes.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\passes.c -o build\1_1\passes.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\types.c -o build\1_1\types.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\types.c -o build\1_1\types.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\trees.c -o build\1_1\trees.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\trees.c -o build\1_1\trees.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\magicsys.c -o build\1_1\magicsys.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\magicsys.c -o build\1_1\magicsys.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\nimsets.c -o build\1_1\nimsets.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\nimsets.c -o build\1_1\nimsets.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\bitsets.c -o build\1_1\bitsets.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\bitsets.c -o build\1_1\bitsets.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\semthreads.c -o build\1_1\semthreads.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\semthreads.c -o build\1_1\semthreads.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\importer.c -o build\1_1\importer.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\importer.c -o build\1_1\importer.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\lookups.c -o build\1_1\lookups.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\lookups.c -o build\1_1\lookups.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\semdata.c -o build\1_1\semdata.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\semdata.c -o build\1_1\semdata.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\treetab.c -o build\1_1\treetab.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\treetab.c -o build\1_1\treetab.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\evals.c -o build\1_1\evals.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\evals.c -o build\1_1\evals.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\semfold.c -o build\1_1\semfold.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\semfold.c -o build\1_1\semfold.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\transf.c -o build\1_1\transf.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\transf.c -o build\1_1\transf.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\cgmeth.c -o build\1_1\cgmeth.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\cgmeth.c -o build\1_1\cgmeth.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\sem.c -o build\1_1\sem.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\sem.c -o build\1_1\sem.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\procfind.c -o build\1_1\procfind.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\procfind.c -o build\1_1\procfind.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\pragmas.c -o build\1_1\pragmas.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\pragmas.c -o build\1_1\pragmas.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\semtypinst.c -o build\1_1\semtypinst.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\semtypinst.c -o build\1_1\semtypinst.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\sigmatch.c -o build\1_1\sigmatch.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\sigmatch.c -o build\1_1\sigmatch.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\suggest.c -o build\1_1\suggest.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\suggest.c -o build\1_1\suggest.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\aliases.c -o build\1_1\aliases.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\aliases.c -o build\1_1\aliases.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\docgen.c -o build\1_1\docgen.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\docgen.c -o build\1_1\docgen.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\rstast.c -o build\1_1\rstast.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\rstast.c -o build\1_1\rstast.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\rst.c -o build\1_1\rst.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\rst.c -o build\1_1\rst.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\rstgen.c -o build\1_1\rstgen.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\rstgen.c -o build\1_1\rstgen.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\highlite.c -o build\1_1\highlite.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\highlite.c -o build\1_1\highlite.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\cgen.c -o build\1_1\cgen.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\cgen.c -o build\1_1\cgen.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\ccgutils.c -o build\1_1\ccgutils.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\ccgutils.c -o build\1_1\ccgutils.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\cgendata.c -o build\1_1\cgendata.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\cgendata.c -o build\1_1\cgendata.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\ccgmerge.c -o build\1_1\ccgmerge.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\ccgmerge.c -o build\1_1\ccgmerge.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\ecmasgen.c -o build\1_1\ecmasgen.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\ecmasgen.c -o build\1_1\ecmasgen.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\passaux.c -o build\1_1\passaux.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\passaux.c -o build\1_1\passaux.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\depends.c -o build\1_1\depends.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\depends.c -o build\1_1\depends.o
ECHO %CC% %COMP_FLAGS% -Ibuild -c build\1_1\parseopt.c -o build\1_1\parseopt.o
%CC% %COMP_FLAGS% -Ibuild -c build\1_1\parseopt.c -o build\1_1\parseopt.o

ECHO %LINKER% %LINK_FLAGS% -o bin\nimrod.exe  build\1_1\nim__dat.o build\1_1\system.o build\1_1\nimrod.o build\1_1\times.o build\1_1\strutils.o build\1_1\parseutils.o build\1_1\winlean.o build\1_1\commands.o build\1_1\os.o build\1_1\msgs.o build\1_1\options.o build\1_1\lists.o build\1_1\strtabs.o build\1_1\hashes.o build\1_1\tables.o build\1_1\math.o build\1_1\nversion.o build\1_1\condsyms.o build\1_1\ast.o build\1_1\crc.o build\1_1\ropes.o build\1_1\platform.o build\1_1\idents.o build\1_1\intsets.o build\1_1\idgen.o build\1_1\astalgo.o build\1_1\rodutils.o build\1_1\extccomp.o build\1_1\osproc.o build\1_1\streams.o build\1_1\wordrecg.o build\1_1\lexer.o build\1_1\lexbase.o build\1_1\llstream.o build\1_1\nimconf.o build\1_1\main.o build\1_1\syntaxes.o build\1_1\parser.o build\1_1\pbraces.o build\1_1\filters.o build\1_1\renderer.o build\1_1\filter_tmpl.o build\1_1\rodread.o build\1_1\memfiles.o build\1_1\rodwrite.o build\1_1\passes.o build\1_1\types.o build\1_1\trees.o build\1_1\magicsys.o build\1_1\nimsets.o build\1_1\bitsets.o build\1_1\semthreads.o build\1_1\importer.o build\1_1\lookups.o build\1_1\semdata.o build\1_1\treetab.o build\1_1\evals.o build\1_1\semfold.o build\1_1\transf.o build\1_1\cgmeth.o build\1_1\sem.o build\1_1\procfind.o build\1_1\pragmas.o build\1_1\semtypinst.o build\1_1\sigmatch.o build\1_1\suggest.o build\1_1\aliases.o build\1_1\docgen.o build\1_1\rstast.o build\1_1\rst.o build\1_1\rstgen.o build\1_1\highlite.o build\1_1\cgen.o build\1_1\ccgutils.o build\1_1\cgendata.o build\1_1\ccgmerge.o build\1_1\ecmasgen.o build\1_1\passaux.o build\1_1\depends.o build\1_1\parseopt.o
%LINKER% %LINK_FLAGS% -o bin\nimrod.exe  build\1_1\nim__dat.o build\1_1\system.o build\1_1\nimrod.o build\1_1\times.o build\1_1\strutils.o build\1_1\parseutils.o build\1_1\winlean.o build\1_1\commands.o build\1_1\os.o build\1_1\msgs.o build\1_1\options.o build\1_1\lists.o build\1_1\strtabs.o build\1_1\hashes.o build\1_1\tables.o build\1_1\math.o build\1_1\nversion.o build\1_1\condsyms.o build\1_1\ast.o build\1_1\crc.o build\1_1\ropes.o build\1_1\platform.o build\1_1\idents.o build\1_1\intsets.o build\1_1\idgen.o build\1_1\astalgo.o build\1_1\rodutils.o build\1_1\extccomp.o build\1_1\osproc.o build\1_1\streams.o build\1_1\wordrecg.o build\1_1\lexer.o build\1_1\lexbase.o build\1_1\llstream.o build\1_1\nimconf.o build\1_1\main.o build\1_1\syntaxes.o build\1_1\parser.o build\1_1\pbraces.o build\1_1\filters.o build\1_1\renderer.o build\1_1\filter_tmpl.o build\1_1\rodread.o build\1_1\memfiles.o build\1_1\rodwrite.o build\1_1\passes.o build\1_1\types.o build\1_1\trees.o build\1_1\magicsys.o build\1_1\nimsets.o build\1_1\bitsets.o build\1_1\semthreads.o build\1_1\importer.o build\1_1\lookups.o build\1_1\semdata.o build\1_1\treetab.o build\1_1\evals.o build\1_1\semfold.o build\1_1\transf.o build\1_1\cgmeth.o build\1_1\sem.o build\1_1\procfind.o build\1_1\pragmas.o build\1_1\semtypinst.o build\1_1\sigmatch.o build\1_1\suggest.o build\1_1\aliases.o build\1_1\docgen.o build\1_1\rstast.o build\1_1\rst.o build\1_1\rstgen.o build\1_1\highlite.o build\1_1\cgen.o build\1_1\ccgutils.o build\1_1\cgendata.o build\1_1\ccgmerge.o build\1_1\ecmasgen.o build\1_1\passaux.o build\1_1\depends.o build\1_1\parseopt.o


ECHO SUCCESS

