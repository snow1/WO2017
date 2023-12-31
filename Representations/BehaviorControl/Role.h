/**
 * @file Representations/BehaviorControl/Role.h
 *
 * Declaration of the representation of a robot's behavior role
 *
 * @author Tim Laue, Andreas Stolpmann
 */

#pragma once

#include "Platform/BHAssert.h"
#include "RoleCheck.h"
#include "Tools/Streams/AutoStreamable.h"
#include "Tools/Streams/Enum.h"
#include <queue>
#include "Tools/Module/Module.h"
#include "Tools/Math/Eigen.h"
/**
 * @struct Role
 * Representation of a robot's behavior role
 */
STREAMABLE(Role,
{
  /** The different roles */
  ENUM(RoleType,
  {,
    undefined,
	keeper,
	striker,
	defender,
	supporter,
	none,
  });

  CHECK_OSCILLATION(role, RoleType, undefined, "Role", 5000)
  /** Draws the current role next to the robot on the field view (in local robot coordinates) */
  void draw() const,

  /** Instance of role */
  //(int)(Global::getSettings().playerNumber) previousRolenumber,
  (RoleType)(undefined) role,
  (int)(1) rolenumber,
  (int)(0) rolenumbers,
});

STREAMABLE(TeammateRoles,
{
  Role::RoleType operator [](const size_t i) const;
  Role::RoleType& operator [](const size_t i);
  static const char* getName(Role::RoleType e),

  (std::vector<Role::RoleType>) roles,
  (int) rolenumber,
  (int)(0) rolenumbers,
});
