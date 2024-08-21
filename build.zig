const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const variables = b.addExecutable(.{ .name = "01_variables", .target = target });

    variables.addCSourceFile(.{ .file = b.path("01_variables/variables.c"), .flags = &[_][]const u8{} });
    variables.linkLibC();

    b.installArtifact(variables);
}
