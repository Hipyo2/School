defmodule Cs491Hm1.OfficeAssetsFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `Cs491Hm1.OfficeAssets` context.
  """

  @doc """
  Generate a printer.
  """
  def printer_fixture(attrs \\ %{}) do
    {:ok, printer} =
      attrs
      |> Enum.into(%{
        building: "some building",
        inventory_code: 42,
        model: "some model",
        office_number: 42
      })
      |> Cs491Hm1.OfficeAssets.create_printer()

    printer
  end

  @doc """
  Generate a computer.
  """
  def computer_fixture(attrs \\ %{}) do
    {:ok, computer} =
      attrs
      |> Enum.into(%{
        brand: "some brand",
        operating_systems_version: 42
      })
      |> Cs491Hm1.OfficeAssets.create_computer()

    computer
  end
end
