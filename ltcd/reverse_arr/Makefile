TARGET = reverse_arr
BUILD_OUTPUT_DIR = ./output

SRC := $(wildcard ./*.cxx)
OBJS := $(SRC:./%.cxx=./$(BUILD_OUTPUT_DIR)/%.o)
DEPS := $(SRC:./%.cxx=./$(BUILD_OUTPUT_DIR)/%.d)

CFLAGS = -g -Wall -Werror 
INCLUDE_PATH = 
LD_FLAGS =
LIBS = 

all::

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

${BUILD_OUTPUT_DIR}/%.d: %.cxx
	@mkdir -p $(BUILD_OUTPUT_DIR)
	$(CXX) -MM -MT "$(BUILD_OUTPUT_DIR)/$(subst .cxx,.o,${notdir $<}) $(BUILD_OUTPUT_DIR)/$(subst .cxx,.d,${notdir $<})" -MF "$(subst .cxx,.d,${BUILD_OUTPUT_DIR}/${notdir $<})" $<

$(BUILD_OUTPUT_DIR)/%.o: %.cxx
	$(CXX) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

# cov : CFLAGS += -fprofile-arcs -ftest-coverage

# cov : LD_FLAGS += -fprofile-arcs -ftest-coverage

all:: ${BUILD_OUTPUT_DIR}/${TARGET}

# gencov:
# 	@cp *.c $(BUILD_OUTPUT_DIR)
# 	@gcov -r -o $(BUILD_OUTPUT_DIR) $(BUILD_OUTPUT_DIR)/*.c

${BUILD_OUTPUT_DIR}/${TARGET}: ${OBJS}
	${CXX} -g -Wall -Werror  ${LD_FLAGS} -o $@  $^ ${LIBS}
#	@mv ${BUILD_OUTPUT_DIR}/${TARGET} ${BUILD_OUTPUT_DIR}/${TARGET}.${VERSION}
#	@ln -s ${BUILD_OUTPUT_DIR}/${TARGET}.${VERSION} ${BUILD_OUTPUT_DIR}/${TARGET}

clean:
	@rm -rf ${OBJS} ${BUILD_OUTPUT_DIR}/${TARGET} ${DEPS}
	@rm -rf *.gcov
#	@rm -rf ../matrix-c-${VERSION}.tar.gz
#	@rm -rf ../matrix-c-${VERSION}
#	@rm -rf ../rpmbuild/SOURCES ../rpmbuild/BUILD  ../rpmbuild/BUILDROOT ../rpmbuild/RPMS ../rpmbuild/SRPMS

# package:
# 	@mkdir -p ../matrix-c-${VERSION}
# 	@cp * ../matrix-c-${VERSION}
# 	@tar -czvf ../matrix-c-${VERSION}.tar.gz ../matrix-c-${VERSION} ../rpmbuild
# 	@mkdir -p ../rpmbuild/SOURCES
# 	@mv ../matrix-c-${VERSION}.tar.gz ../rpmbuild/SOURCES

.PHONY: clean 