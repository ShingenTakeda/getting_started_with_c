const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const setup = b.addExecutable(.{ .name = "00_setup", .target = target });
    const variables = b.addExecutable(.{ .name = "01_variables_and_control", .target = target });

    setup.addCSourceFile(.{ .file = b.path("00_setup/hello.c"), .flags = &[_][]const u8{} });
    setup.linkLibC();

    variables.addCSourceFile(.{ .file = b.path("01_variables_and_control/variables.c"), .flags = &[_][]const u8{} });
    variables.linkLibC();

    b.installArtifact(setup);
    b.installArtifact(variables);
}
