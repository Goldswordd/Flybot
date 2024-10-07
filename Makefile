ENGINE = podman
RUN = ${ENGINE} run -v $$(pwd):/bulebule:Z --privileged bulebule

ifeq (, $(shell ${ENGINE} --version 2> /dev/null))
$(warning "Command `${ENGINE}` not found, falling back to Docker...")
ENGINE = sudo docker
RUN = ${ENGINE} run -v $$(pwd):/bulebule:Z -u $$(id -u):$$(id -g) bulebule
endif

default: src

.PHONY: src
src:
	${RUN} make -C src/

.PHONY: flash
flash:
	flash: /home/ponp/bulebule/src/main.elf
	openocd -f interface/stlink-v2.cfg -f ~/bulebule/stm32f1x.cfg -c "program micromouse.elf verify reset exit"

.PHONY: libopencm3
libopencm3:
	${RUN} scripts/setup_libopencm3.sh

.PHONY: clean
clean:
	${RUN} make -s -C src/ clean

.PHONY: image
image:
	${ENGINE} build -t bulebule .



